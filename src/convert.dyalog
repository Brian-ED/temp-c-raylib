
⎕io←0
Assert ← {⍺←'assertion failure' ⋄ 0∊⍵:⍺ ⎕SIGNAL 8 ⋄ shy←0}
CI ← { ⍝ ,⍣¯1 but better. CI = Concatinate Inverse
  _←Assert 1 1≡≢∘⍴¨⍺⍵
  _←Assert ⍺≤⍥≢⍵
  _←Assert ⍺≡⍵↑⍨≢⍺
  ⍵↓⍨≢⍺
}
CTI ← { ⍝ ,⍨⍣¯1 but better. CTI = Concatinate Tilda Inverse
  _←Assert 1 1≡≢∘⍴¨⍺⍵
  _←Assert ⍺≤⍥≢⍵
  _←Assert ⍺≡⍵↑⍨-≢⍺
  ⍵↓⍨-≢⍺
}⍨
⍝ validTypes ← ⍬
⍝ validTypes ,←⊂ 'bool '
⍝ validTypes ,←⊂ 'int '
⍝ validTypes ,←⊂ 'void *'
fixDecleration ← {
  retTypeAndName ← ⍵↑⍨⊃⍸'('=⍵
  retType ← {⍵/⍨~⌽∧\⌽(⎕A,⎕D)∊⍨1⎕C⍵} retTypeAndName
  retType≡'void ' : ''
  name ← retType CI retTypeAndName
  argTypesAndOnwards ← (,'(') CI name CI retType CI ⍵
  argTypesAndOnwards CI⍨← 'void'/⍨'void)'≡5↑argTypesAndOnwards ⍝ remove void when we add return argument
  newArgTypesAndOnwards ← argTypesAndOnwards,⍨retType,'*ret',', '/⍨')'≠⊃argTypesAndOnwards

  (argTypes newArgTypes) ← {⍵/⍨⌽∨\⌽¯1⌽');'⍷⍵}¨(argTypesAndOnwards newArgTypesAndOnwards)
  onwards ← argTypes CI argTypesAndOnwards
  argsNames ← ');',⍨ 2↓⊃,/', '∘,¨ {⍵/⍨⌽∧\⌽(⎕A,⎕D)∊⍨1⎕C⍵}¨ ', '(~⍤⍷⊆⊢) ({⍵↓⍨-';'=⊃⌽⍵}argTypes) CTI ,')'

  funcDefAndOnwards ← '{*ret=',name,'(',argsNames,'}',onwards

  'void ',name,'RetPtr(',(newArgTypes CTI ,';'), funcDefAndOnwards
}

⍝IsDecleration ← {
⍝  comment←∨\'//'⍷⍵
⍝  spaces←' '=⍵
⍝  decl ← ~⌽∧\⌽spaces∨comment
⍝  o1←{(');'≡⍵)∨')'≡⊃⌽⍵}⍵/⍨decl>2⌽decl
⍝  o2←∧/0≤+\-⌿'()'∘.=⍵
⍝  o3 ← ~∨/(1 ⎕C 'typedef' 'if') ∊⍨(⎕A,⎕D)(∊⍨⊆⊢)1 ⎕C ⍵
⍝  o4←' '≠⊃⍵
⍝
⍝  retTypeAndName ← ⍵↑⍨⊃⍸'('=⍵
⍝  retType ← {⍵/⍨⌽∧\⌽(⎕A,⎕D)∊⍨1⎕C⍵} retTypeAndName
⍝  name ← (≢retType)↓ retTypeAndName
⍝  o5←0≢≢name
⍝  o6←~∨/'{}'∊⍵
⍝
⍝  o1∧o2∧o3∧o4∧o5∧o6
⍝}
⍝⎕←IsDecleration 'RLAPI void *func(type *name);   // lala'
⍝⎕←IsDecleration 'void *func(type *name);   // lala'
⍝⎕←IsDecleration 'RLAPI ModelAnimation *LoadModelAnimations(const char *fileName, int *animCount);            // Load model animations from file'
⍝⎕←IsDecleration 'RLAPI void UpdateModelAnimation(Model model, ModelAnimation anim, int frame);               // Update model animation pose'
⍝⎕←IsDecleration 'RLAPI void UnloadModelAnimation(ModelAnimation anim);                                       // Unload animation data'
⍝⎕←IsDecleration 'RLAPI void UnloadModelAnimations(ModelAnimation *animations, int animCount);                // Unload animation array data'
⍝⎕←IsDecleration 'RLAPI bool IsModelAnimationValid(Model model, ModelAnimation anim);                         // Check model animation skeleton match'

includes ← ⍬
includes ,←⊂ '#include "raylib.h"'
includes ,←⊂ '#include "raymath.h"'
includes ,←⊂ '#include "rlgl.h"'
includes ,←⊂ '#define RAYGUI_IMPLEMENTATION'
includes ,←⊂ '#include "raygui.h"'
includes ,←⊂ '#define PHYSAC_IMPLEMENTATION'
includes ,←⊂ '#include "physac.h"'

functionsStart ← ⍬
functionsStart ,←⊂ '#if defined(__cplusplus)'
functionsStart ,←⊂ 'extern "C" {            // Prevents name mangling of functions'
functionsStart ,←⊂ '#endif'

functionsEnd ← ⍬
functionsEnd ,←⊂ '#if defined(__cplusplus)'
functionsEnd ,←⊂ ,'}'
functionsEnd ,←⊂ '#endif'

(rl rm rlgl) ← (⊃⍤⎕NGET 1,⍨⊂)¨ '../build/_deps/raylib-build/raylib/include/'∘,¨'raylib.h' 'raymath.h' 'rlgl.h'
rgui         ← (⊃⍤⎕NGET 1,⍨⊂) 'raygui.h'
physac       ← (⊃⍤⎕NGET 1,⍨⊂) 'physac.h'

physacFuncs  ←   physac {⍵CI¨⍺/⍨⍵≡¨10↑¨⍺} ⊂'PHYSACDEF '
rayguiFuncs  ←     rgui {⍵CI¨⍺/⍨⍵≡¨10↑¨⍺} ⊂'RAYGUIAPI '
raylibFuncs  ←       rl {⍵CI¨⍺/⍨⍵≡¨ 6↑¨⍺} ⊂'RLAPI '
raymathFuncs ← ';',⍨¨rm {⍵CI¨⍺/⍨⍵≡¨ 6↑¨⍺} ⊂'RMAPI '

⍝           /¯¯¯fixes bug in rl 5.0¯¯¯¯\
rlglFuncs   ← (  rlgl/⍨~∨\functionsEnd⍷  rlgl) {⍵CI¨⍺/⍨⍵≡¨ 6↑¨⍺} ⊂'RLAPI '
physacFuncs ← (physac/⍨~∨\functionsEnd⍷physac) {⍵CI¨⍺/⍨⍵≡¨10↑¨⍺} ⊂'PHYSACDEF '



declorations ← ⊃,/(raylibFuncs raymathFuncs rlglFuncs rayguiFuncs)
fixed ← {⍵/⍨0≠≢¨⍵} fixDecleration¨ {⍵/⍨∧/3∨/'.'≠↑⍵} declorations
'temp-c-raylib.c'1⎕NPUT⍨⊂includes, fixed
