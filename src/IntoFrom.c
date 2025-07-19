#ifndef RLAPI
  #define RLAPI
#endif
#define DECLARE(x) RLAPI x; x

/*typedef struct Vector2 {
  float x;
  float y;
} Vector2; */
DECLARE(void Vector2INTO(
  Vector2 *R,
  float *x,
  float *y)){
  R->x = *x;
  R->y = *y;
}
DECLARE(void Vector2FROM(
  Vector2 *R,
  float *x,
  float *y)){
  *x = R->x;
  *y = R->y;
}


/*typedef struct Vector3 {
  float x;
  float y;
  float z;
} Vector3; */
DECLARE(void Vector3INTO(
  Vector3 *R,
  float *x,
  float *y,
  float *z)){
  R->x = *x;
  R->y = *y;
  R->z = *z;
}
DECLARE(void Vector3FROM(
  Vector3 *R,
  float *x,
  float *y,
  float *z)){
  *x = R->x;
  *y = R->y;
  *z = R->z;
}


/*typedef struct Vector4 {
  float x;
  float y;
  float z;
  float w;
} Vector4; */
DECLARE(void Vector4INTO(
  Vector4 *R,
  float *x,
  float *y,
  float *z,
  float *w)){
  R->x = *x;
  R->y = *y;
  R->z = *z;
  R->w = *w;
}
DECLARE(void Vector4FROM(
  Vector4 *R,
  float *x,
  float *y,
  float *z,
  float *w)){
  *x = R->x;
  *y = R->y;
  *z = R->z;
  *w = R->w;
}


/*typedef struct Matrix {
  float m0, m4, m8, m12;
  float m1, m5, m9, m13;
  float m2, m6, m10, m14;
  float m3, m7, m11, m15;
} Matrix; */
DECLARE(void MatrixFROM(
  Matrix *R,
  float *m0, float *m4, float *m8 , float *m12,
  float *m1, float *m5, float *m9 , float *m13,
  float *m2, float *m6, float *m10, float *m14,
  float *m3, float *m7, float *m11, float *m15)){
  *m0=R->m0; *m4=R->m4; *m8 =R->m8 ; *m12=R->m12;
  *m1=R->m1; *m5=R->m5; *m9 =R->m9 ; *m13=R->m13;
  *m2=R->m2; *m6=R->m6; *m10=R->m10; *m14=R->m14;
  *m3=R->m3; *m7=R->m7; *m11=R->m11; *m15=R->m15;
}
DECLARE(void MatrixINTO(
  Matrix *R,
  float *m0, float *m4, float *m8 , float *m12,
  float *m1, float *m5, float *m9 , float *m13,
  float *m2, float *m6, float *m10, float *m14,
  float *m3, float *m7, float *m11, float *m15)){
  R->m0=*m0; R->m4=*m4; R->m8 =*m8 ; R->m12=*m12;
  R->m1=*m1; R->m5=*m5; R->m9 =*m9 ; R->m13=*m13;
  R->m2=*m2; R->m6=*m6; R->m10=*m10; R->m14=*m14;
  R->m3=*m3; R->m7=*m7; R->m11=*m11; R->m15=*m15;
}


/*typedef struct Color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
} Color; */
DECLARE(void ColorINTO(
  Color *R,
  unsigned char *r,
  unsigned char *g,
  unsigned char *b,
  unsigned char *a)){
  R->r = *r;
  R->g = *g;
  R->b = *b;
  R->a = *a;
}
DECLARE(void ColorFROM(
  Color *R,
  unsigned char *r,
  unsigned char *g,
  unsigned char *b,
  unsigned char *a)){
  *r = R->r;
  *g = R->g;
  *b = R->b;
  *a = R->a;
}


/*typedef struct Rectangle {
  float x;
  float y;
  float width;
  float height;
} Rectangle; */
DECLARE(void RectangleINTO(
  Rectangle *R,
  float *x,
  float *y,
  float *width,
  float *height)){
  R->x = *x;
  R->y = *y;
  R->width = *width;
  R->height = *height;
}
DECLARE(void RectangleFROM(
  Rectangle *R,
  float *x,
  float *y,
  float *width,
  float *height)){
  *x = R->x;
  *y = R->y;
  *width = R->width;
  *height = R->height;
}


/*typedef struct Image {
  void *data;
  int width;
  int height;
  int mipmaps;
  int format;
} Image; */
DECLARE(void ImageINTO(
  Image *R,
  void **data,
  int  *width,
  int  *height,
  int  *mipmaps,
  int  *format)){
  R->data = *data;
  R->width = *width;
  R->height = *height;
  R->mipmaps = *mipmaps;
  R->format = *format;
}
DECLARE(void ImageFROM(
  Image *R,
  void **data,
  int *width,
  int *height,
  int *mipmaps,
  int *format)){
  *data = R->data;
  *width = R->width;
  *height = R->height;
  *mipmaps = R->mipmaps;
  *format = R->format;
}


/*typedef struct Texture {
  unsigned int id;
  int width;
  int height;
  int mipmaps;
  int format;
} Texture; */
DECLARE(void TextureINTO(
  Texture *R,
  unsigned int *id,
  int *width,
  int *height,
  int *mipmaps,
  int *format)){
  R->id = *id;
  R->width = *width;
  R->height = *height;
  R->mipmaps = *mipmaps;
  R->format = *format;
}
DECLARE(void TextureFROM(
  Texture *R,
  unsigned int *id,
  int *width,
  int *height,
  int *mipmaps,
  int *format)){
  *id = R->id;
  *width = R->width;
  *height = R->height;
  *mipmaps = R->mipmaps;
  *format = R->format;
}


/*typedef struct RenderTexture {
  unsigned int id;
  Texture texture;
  Texture depth;
} RenderTexture; */
// typedef RenderTexture RenderTexture2D;
DECLARE(void RenderTextureINTO(
  RenderTexture *R,
  unsigned int *id,
  Texture *texture,
  Texture *depth)){
  R->id      = *id;
  R->texture = *texture;
  R->depth   = *depth;
}
DECLARE(void RenderTextureFROM(
  RenderTexture *R,
  unsigned int *id,
  Texture *texture,
  Texture *depth)){
  *id      = R->id;
  *texture = R->texture;
  *depth   = R->depth;
}


/*typedef struct NPatchInfo {
  Rectangle source;
  int left;
  int top;
  int right;
  int bottom;
  int layout;
} NPatchInfo; */
DECLARE(void NPatchInfoINTO(
  NPatchInfo *R,
  Rectangle *source,
  int *left,
  int *top,
  int *right,
  int *bottom,
  int *layout)){
  R->source = *source;
  R->left = *left;
  R->top = *top;
  R->right = *right;
  R->bottom = *bottom;
  R->layout = *layout;
}
DECLARE(void NPatchInfoFROM(
  NPatchInfo *R,
  Rectangle *source,
  int *left,
  int *top,
  int *right,
  int *bottom,
  int *layout)){
  *source = R->source;
  *left = R->left;
  *top = R->top;
  *right = R->right;
  *bottom = R->bottom;
  *layout = R->layout;
}


/*typedef struct GlyphInfo {
  int value;
  int offsetX;
  int offsetY;
  int advanceX;
  Image image;
} GlyphInfo; */
DECLARE(void GlyphInfoINTO(
  GlyphInfo *R,
  int *value,
  int *offsetX,
  int *offsetY,
  int *advanceX,
  Image *image)){
  R->value = *value;
  R->offsetX = *offsetX;
  R->offsetY = *offsetY;
  R->advanceX = *advanceX;
  R->image = *image;
}
DECLARE(void GlyphInfoFROM(
  GlyphInfo *R,
  int *value,
  int *offsetX,
  int *offsetY,
  int *advanceX,
  Image *image)){
  *value = R->value;
  *offsetX = R->offsetX;
  *offsetY = R->offsetY;
  *advanceX = R->advanceX;
  *image = R->image;
}


/*typedef struct Font {
  int baseSize;
  int glyphCount;
  int glyphPadding;
  Texture2D texture;
  Rectangle *recs;
  GlyphInfo *glyphs;
} Font; */
DECLARE(void FontINTO(
  Font *R,
  int *baseSize,
  int *glyphCount,
  int *glyphPadding,
  Texture2D *texture,
  Rectangle **recs,
  GlyphInfo **glyphs)){
  R->baseSize = *baseSize;
  R->glyphCount = *glyphCount;
  R->glyphPadding = *glyphPadding;
  R->texture = *texture;
  R->recs = *recs;
  R->glyphs = *glyphs;
}
DECLARE(void FontFROM(
  Font *R,
  int *baseSize,
  int *glyphCount,
  int *glyphPadding,
  Texture2D *texture,
  Rectangle **recs,
  GlyphInfo **glyphs)){
  *baseSize = R->baseSize;
  *glyphCount = R->glyphCount;
  *glyphPadding = R->glyphPadding;
  *texture = R->texture;
  *recs = R->recs;
  *glyphs = R->glyphs;
}


/*typedef struct Camera3D {
  Vector3 position;
  Vector3 target;
  Vector3 up;
  float fovy;
  int projection;
} Camera3D; */
DECLARE(void Camera3DINTO(
  Camera3D *R,
  Vector3 *position,
  Vector3 *target,
  Vector3 *up,
  float *fovy,
  int *projection)){
  R->position = *position;
  R->target = *target;
  R->up = *up;
  R->fovy = *fovy;
  R->projection = *projection;
}
DECLARE(void Camera3DFROM(
  Camera3D *R,
  Vector3 *position,
  Vector3 *target,
  Vector3 *up,
  float *fovy,
  int *projection)){
  *position = R->position;
  *target = R->target;
  *up = R->up;
  *fovy = R->fovy;
  *projection = R->projection;
}


/*typedef struct Camera2D {
  Vector2 offset;
  Vector2 target;
  float rotation;
  float zoom;
} Camera2D; */
DECLARE(void Camera2DINTO(
  Camera2D *R,
  Vector2 *offset,
  Vector2 *target,
  float *rotation,
  float *zoom)){
  R->offset = *offset;
  R->target = *target;
  R->rotation = *rotation;
  R->zoom = *zoom;
}
DECLARE(void Camera2DFROM(
  Camera2D *R,
  Vector2 *offset,
  Vector2 *target,
  float *rotation,
  float *zoom)){
  *offset = R->offset;
  *target = R->target;
  *rotation = R->rotation;
  *zoom = R->zoom;
}


/*typedef struct Mesh {
  int vertexCount;
  int triangleCount;
  float *vertices;
  float *texcoords;
  float *texcoords2;
  float *normals;
  float *tangents;
  unsigned char *colors;
  unsigned short *indices;
  float *animVertices;
  float *animNormals;
  unsigned char *boneIds;
  float *boneWeights;
  Matrix *boneMatrices;
  int boneCount;
  unsigned int vaoId;
  unsigned int *vboId;
} Mesh; */
DECLARE(void MeshINTO(
  Mesh *R,
  int *vertexCount,
  int *triangleCount,
  float **vertices,
  float **texcoords,
  float **texcoords2,
  float **normals,
  float **tangents,
  unsigned char **colors,
  unsigned short **indices,
  float **animVertices,
  float **animNormals,
  unsigned char **boneIds,
  float **boneWeights,
  Matrix **boneMatrices,
  int *boneCount,
  unsigned int *vaoId,
  unsigned int **vboId)){
  R->vertexCount = *vertexCount;
  R->triangleCount = *triangleCount;
  R->vertices = *vertices;
  R->texcoords = *texcoords;
  R->texcoords2 = *texcoords2;
  R->normals = *normals;
  R->tangents = *tangents;
  R->colors = *colors;
  R->indices = *indices;
  R->animVertices = *animVertices;
  R->animNormals = *animNormals;
  R->boneIds = *boneIds;
  R->boneWeights = *boneWeights;
  R->boneMatrices = *boneMatrices;
  R->boneCount = *boneCount;
  R->vaoId = *vaoId;
  R->vboId = *vboId;
}
DECLARE(void MeshFROM(
  Mesh *R,
  int *vertexCount,
  int *triangleCount,
  float **vertices,
  float **texcoords,
  float **texcoords2,
  float **normals,
  float **tangents,
  unsigned char **colors,
  unsigned short **indices,
  float **animVertices,
  float **animNormals,
  unsigned char **boneIds,
  float **boneWeights,
  Matrix **boneMatrices,
  int *boneCount,
  unsigned int *vaoId,
  unsigned int **vboId)){
  *vertexCount = R->vertexCount;
  *triangleCount = R->triangleCount;
  *vertices = R->vertices;
  *texcoords = R->texcoords;
  *texcoords2 = R->texcoords2;
  *normals = R->normals;
  *tangents = R->tangents;
  *colors = R->colors;
  *indices = R->indices;
  *animVertices = R->animVertices;
  *animNormals = R->animNormals;
  *boneIds = R->boneIds;
  *boneWeights = R->boneWeights;
  *boneMatrices = R->boneMatrices;
  *boneCount = R->boneCount;
  *vaoId = R->vaoId;
  *vboId = R->vboId;
}


/*typedef struct Shader {
  unsigned int id;
  int *locs;
} Shader; */
DECLARE(void ShaderINTO(
  Shader *R,
  unsigned int *id,
  int **locs)){
  R->id = *id;
  R->locs = *locs;
}
DECLARE(void ShaderFROM(
  Shader *R,
  unsigned int *id,
  int **locs)){
  *id = R->id;
  *locs = R->locs;
}


/*typedef struct MaterialMap {
  Texture2D texture;
  Color color;
  float value;
} MaterialMap; */
DECLARE(void MaterialMapINTO(
  MaterialMap *R,
  Texture2D *texture,
  Color *color,
  float *value)){
  R->texture = *texture;
  R->color = *color;
  R->value = *value;
}
DECLARE(void MaterialMapFROM(
  MaterialMap *R,
  Texture2D *texture,
  Color *color,
  float *value)){
  *texture = R->texture;
  *color = R->color;
  *value = R->value;
}


/*typedef struct Material {
  Shader shader;
  MaterialMap *maps;
  float params[4];
} Material; */
DECLARE(void MaterialINTO(
  Material *R,
  Shader *shader,
  MaterialMap **maps,
  float (*params)[4])){
  R->shader    = *shader;
  R->maps      = *maps;
  for(int i=0;i<4;i++) R->params[i] = (*params)[i];
}
DECLARE(void MaterialFROM(
  Material *R,
  Shader *shader,
  MaterialMap **maps,
  float (*params)[4])){
  *shader = R->shader;
  *maps = R->maps;
  for(int i=0;i<4;i++) (*params)[i] = R->params[i];
}


/*typedef struct Transform {
  Vector3 translation;
  Quaternion rotation;
  Vector3 scale;
} Transform; */
DECLARE(void TransformINTO(
  Transform *R,
  Vector3 *translation,
  Quaternion *rotation,
  Vector3 *scale)){
  R->translation = *translation;
  R->rotation = *rotation;
  R->scale = *scale;
}
DECLARE(void TransformFROM(
  Transform *R,
  Vector3 *translation,
  Quaternion *rotation,
  Vector3 *scale)){
  *translation = R->translation;
  *rotation = R->rotation;
  *scale = R->scale;
}


/*typedef struct BoneInfo {
  char name[32];
  int parent;
} BoneInfo; */
DECLARE(void BoneInfoINTO(
  BoneInfo *R,
  char (*name)[32],
  int *parent)){
  for(int i=0;i<32;i++) R->name[i] = (*name)[i];
  R->parent = *parent;
}
DECLARE(void BoneInfoFROM(
  BoneInfo *R,
  char (*name)[32],
  int *parent)){
  for(int i=0;i<32;i++) (*name)[i] = R->name[i];
  *parent = R->parent;
}


/*typedef struct Model {
  Matrix transform;
  int meshCount;
  int materialCount;
  Mesh *meshes;
  Material *materials;
  int *meshMaterial;
  int boneCount;
  BoneInfo *bones;
  Transform *bindPose;
} Model; */
DECLARE(void ModelINTO(
  Model *R,
  Matrix *transform,
  int *meshCount,
  int *materialCount,
  Mesh **meshes,
  Material **materials,
  int **meshMaterial,
  int *boneCount,
  BoneInfo **bones,
  Transform **bindPose)){
  R->transform = *transform;
  R->meshCount = *meshCount;
  R->materialCount = *materialCount;
  R->meshes = *meshes;
  R->materials = *materials;
  R->meshMaterial = *meshMaterial;
  R->boneCount = *boneCount;
  R->bones = *bones;
  R->bindPose = *bindPose;
}
DECLARE(void ModelFROM(
  Model *R,
  Matrix *transform,
  int *meshCount,
  int *materialCount,
  Mesh **meshes,
  Material **materials,
  int **meshMaterial,
  int *boneCount,
  BoneInfo **bones,
  Transform **bindPose)){
  *transform = R->transform;
  *meshCount = R->meshCount;
  *materialCount = R->materialCount;
  *meshes = R->meshes;
  *materials = R->materials;
  *meshMaterial = R->meshMaterial;
  *boneCount = R->boneCount;
  *bones = R->bones;
  *bindPose = R->bindPose;
}


/*typedef struct ModelAnimation {
  int boneCount;
  int frameCount;
  BoneInfo *bones;
  Transform **framePoses;
  char name[32];
} ModelAnimation; */
DECLARE(void ModelAnimationINTO(
  ModelAnimation *R,
  int *boneCount,
  int *frameCount,
  BoneInfo **bones,
  Transform ***framePoses,
  char (*name)[32])){
  R->boneCount = *boneCount;
  R->frameCount = *frameCount;
  R->bones = *bones;
  R->framePoses = *framePoses;
  for(int i=0;i<32;i++) R->name[i] = (*name)[i];
}
DECLARE(void ModelAnimationFROM(
  ModelAnimation *R,
  int *boneCount,
  int *frameCount,
  BoneInfo **bones,
  Transform ***framePoses,
  char (*name)[32])){

  *boneCount = R->boneCount;
  *frameCount = R->frameCount;
  *bones = R->bones;
  *framePoses = R->framePoses;
  for(int i=0;i<32;i++) (*name)[i] = R->name[i];
}


/*typedef struct Ray {
  Vector3 position;
  Vector3 direction;
} Ray; */
DECLARE(void RayINTO(
  Ray *R,
  Vector3 *position,
  Vector3 *direction)){
  R->position = *position;
  R->direction = *direction;
}
DECLARE(void RayFROM(
  Ray *R,
  Vector3 *position,
  Vector3 *direction)){
  *position = R->position;
  *direction = R->direction;
}


/*typedef struct RayCollision {
  bool hit;
  float distance;
  Vector3 point;
  Vector3 normal;
} RayCollision; */
DECLARE(void RayCollisionINTO(
  RayCollision *R,
  bool *hit,
  float *distance,
  Vector3 *point,
  Vector3 *normal)){
  R->hit = *hit;
  R->distance = *distance;
  R->point = *point;
  R->normal = *normal;
}
DECLARE(void RayCollisionFROM(
  RayCollision *R,
  bool *hit,
  float *distance,
  Vector3 *point,
  Vector3 *normal)){
  *hit = R->hit;
  *distance = R->distance;
  *point = R->point;
  *normal = R->normal;
}


/*typedef struct BoundingBox {
  Vector3 min;
  Vector3 max;
} BoundingBox; */
DECLARE(void BoundingBoxINTO(
  BoundingBox *R,
  Vector3 *min,
  Vector3 *max)){
  R->min = *min;
  R->max = *max;
}
DECLARE(void BoundingBoxFROM(
  BoundingBox *R,
  Vector3 *min,
  Vector3 *max)){
  *min = R->min;
  *max = R->max;
}


/*typedef struct Wave {
  unsigned int frameCount;
  unsigned int sampleRate;
  unsigned int sampleSize;
  unsigned int channels;
  void *data;
} Wave; */
DECLARE(void WaveINTO(
  Wave *R,
  unsigned int *frameCount,
  unsigned int *sampleRate,
  unsigned int *sampleSize,
  unsigned int *channels,
  void **data)){
  R->frameCount = *frameCount;
  R->sampleRate = *sampleRate;
  R->sampleSize = *sampleSize;
  R->channels = *channels;
  R->data = *data;
}
DECLARE(void WaveFROM(
  Wave *R,
  unsigned int *frameCount,
  unsigned int *sampleRate,
  unsigned int *sampleSize,
  unsigned int *channels,
  void **data)){
  *frameCount = R->frameCount;
  *sampleRate = R->sampleRate;
  *sampleSize = R->sampleSize;
  *channels = R->channels;
  *data = R->data;
}


/*typedef struct AudioStream {
  rAudioBuffer *buffer;
  rAudioProcessor *processor;
  unsigned int sampleRate;
  unsigned int sampleSize;
  unsigned int channels;
} AudioStream; */
DECLARE(void AudioStreamINTO(
  AudioStream *R,
  rAudioBuffer **buffer,
  rAudioProcessor **processor,
  unsigned int *sampleRate,
  unsigned int *sampleSize,
  unsigned int *channels)){
  R->buffer = *buffer;
  R->processor = *processor;
  R->sampleRate = *sampleRate;
  R->sampleSize = *sampleSize;
  R->channels = *channels;
}
DECLARE(void AudioStreamFROM(
  AudioStream *R,
  rAudioBuffer **buffer,
  rAudioProcessor **processor,
  unsigned int *sampleRate,
  unsigned int *sampleSize,
  unsigned int *channels)){
  *buffer = R->buffer;
  *processor = R->processor;
  *sampleRate = R->sampleRate;
  *sampleSize = R->sampleSize;
  *channels = R->channels;
}


/*typedef struct Sound {
  AudioStream stream;
  unsigned int frameCount;
} Sound; */
DECLARE(void SoundINTO(
  Sound *R,
  AudioStream *stream,
  unsigned int *frameCount)){
  R->stream = *stream;
  R->frameCount = *frameCount;
}
DECLARE(void SoundFROM(
  Sound *R,
  AudioStream *stream,
  unsigned int *frameCount)){
  *stream = R->stream;
  *frameCount = R->frameCount;
}


/*typedef struct Music {
  AudioStream stream;
  unsigned int frameCount;
  bool looping;
  int ctxType;
  void *ctxData;
} Music; */
DECLARE(void MusicINTO(
  Music *R,
  AudioStream *stream,
  unsigned int *frameCount,
  bool *looping,
  int *ctxType,
  void **ctxData)){
  R->stream = *stream;
  R->frameCount = *frameCount;
  R->looping = *looping;
  R->ctxType = *ctxType;
  R->ctxData = *ctxData;
}
DECLARE(void MusicFROM(
  Music *R,
  AudioStream *stream,
  unsigned int *frameCount,
  bool *looping,
  int *ctxType,
  void **ctxData)){
  *stream = R->stream;
  *frameCount = R->frameCount;
  *looping = R->looping;
  *ctxType = R->ctxType;
  *ctxData = R->ctxData;
}


/*typedef struct VrDeviceInfo {
  int hResolution;
  int vResolution;
  float hScreenSize;
  float vScreenSize;
  float eyeToScreenDistance;
  float lensSeparationDistance;
  float interpupillaryDistance;
  float lensDistortionValues[4];
  float chromaAbCorrection[4];
} VrDeviceInfo; */
DECLARE(void VrDeviceInfoINTO(
  VrDeviceInfo *R,
  int *hResolution,
  int *vResolution,
  float *hScreenSize,
  float *vScreenSize,
  float *eyeToScreenDistance,
  float *lensSeparationDistance,
  float *interpupillaryDistance,
  float (*lensDistortionValues)[4],
  float (*chromaAbCorrection)[4])){
  R->hResolution = *hResolution;
  R->vResolution = *vResolution;
  R->hScreenSize = *hScreenSize;
  R->vScreenSize = *vScreenSize;
  R->eyeToScreenDistance = *eyeToScreenDistance;
  R->lensSeparationDistance = *lensSeparationDistance;
  R->interpupillaryDistance = *interpupillaryDistance;
  for(int i=0;i<4;i++) R->lensDistortionValues[i] = (*lensDistortionValues)[i];
  for(int i=0;i<4;i++) R->chromaAbCorrection[i] = (*chromaAbCorrection)[i];
}
DECLARE(void VrDeviceInfoFROM(
  VrDeviceInfo *R,
  int *hResolution,
  int *vResolution,
  float *hScreenSize,
  float *vScreenSize,
  float *eyeToScreenDistance,
  float *lensSeparationDistance,
  float *interpupillaryDistance,
  float (*lensDistortionValues)[4],
  float (*chromaAbCorrection)[4])){
  *hResolution = R->hResolution;
  *vResolution = R->vResolution;
  *hScreenSize = R->hScreenSize;
  *vScreenSize = R->vScreenSize;
  *eyeToScreenDistance = R->eyeToScreenDistance;
  *lensSeparationDistance = R->lensSeparationDistance;
  *interpupillaryDistance = R->interpupillaryDistance;
  for(int i=0;i<4;i++) (*lensDistortionValues)[i] = R->lensDistortionValues[i];
  for(int i=0;i<4;i++) (*chromaAbCorrection)[i] = R->chromaAbCorrection[i];
}


/*typedef struct VrStereoConfig {
  Matrix projection[2];
  Matrix viewOffset[2];
  float leftLensCenter[2];
  float rightLensCenter[2];
  float leftScreenCenter[2];
  float rightScreenCenter[2];
  float scale[2];
  float scaleIn[2];
} VrStereoConfig; */
DECLARE(void VrStereoConfigINTO(
  VrStereoConfig *R,
  Matrix (*projection)[2],
  Matrix (*viewOffset)[2],
  float (*leftLensCenter)[2],
  float (*rightLensCenter)[2],
  float (*leftScreenCenter)[2],
  float (*rightScreenCenter)[2],
  float (*scale)[2],
  float (*scaleIn)[2])){
  for(int i=0;i<2;i++)R->projection[i] = (*projection)[i];
  for(int i=0;i<2;i++)R->viewOffset[i] = (*viewOffset)[i];
  for(int i=0;i<2;i++)R->leftLensCenter[i] = (*leftLensCenter)[i];
  for(int i=0;i<2;i++)R->rightLensCenter[i] = (*rightLensCenter)[i];
  for(int i=0;i<2;i++)R->leftScreenCenter[i] = (*leftScreenCenter)[i];
  for(int i=0;i<2;i++)R->rightScreenCenter[i] = (*rightScreenCenter)[i];
  for(int i=0;i<2;i++)R->scale[i] = (*scale)[i];
  for(int i=0;i<2;i++)R->scaleIn[i] = (*scaleIn)[i];
}
DECLARE(void VrStereoConfigFROM(
  VrStereoConfig *R,
  Matrix (*projection)[2],
  Matrix (*viewOffset)[2],
  float (*leftLensCenter)[2],
  float (*rightLensCenter)[2],
  float (*leftScreenCenter)[2],
  float (*rightScreenCenter)[2],
  float (*scale)[2],
  float (*scaleIn)[2])){
  for(int i=0;i<2;i++) (*projection)[i] = R->projection[i];
  for(int i=0;i<2;i++) (*viewOffset)[i] = R->viewOffset[i];
  for(int i=0;i<2;i++) (*leftLensCenter)[i] = R->leftLensCenter[i];
  for(int i=0;i<2;i++) (*rightLensCenter)[i] = R->rightLensCenter[i];
  for(int i=0;i<2;i++) (*leftScreenCenter)[i] = R->leftScreenCenter[i];
  for(int i=0;i<2;i++) (*rightScreenCenter)[i] = R->rightScreenCenter[i];
  for(int i=0;i<2;i++) (*scale)[i] = R->scale[i];
  for(int i=0;i<2;i++) (*scaleIn)[i] = R->scaleIn[i];
}


/*typedef struct FilePathList {
  unsigned int capacity;
  unsigned int count;
  char **paths;
} FilePathList; */
DECLARE(void FilePathListINTO(
  FilePathList *R,
  unsigned int *capacity,
  unsigned int *count,
  char ***paths)){
  R->capacity = *capacity;
  R->count = *count;
  R->paths = *paths;
}
DECLARE(void FilePathListFROM(
  FilePathList *R,
  unsigned int *capacity,
  unsigned int *count,
  char ***paths)){
  *capacity = R->capacity;
  *count = R->count;
  *paths = R->paths;
}


/*typedef struct AutomationEvent {
  unsigned int frame;
  unsigned int type;
  int params[4];
} AutomationEvent; */
DECLARE(void AutomationEventINTO(
  AutomationEvent *R,
  unsigned int *frame,
  unsigned int *type,
  int (*params)[4])){
  R->frame = *frame;
  R->type = *type;
  for(int i=0;i<4;i++)R->params[i] = (*params)[i];
}
DECLARE(void AutomationEventFROM(
  AutomationEvent *R,
  unsigned int *frame,
  unsigned int *type,
  int (*params)[4])){
  *frame = R->frame;
  *type = R->type;
  for(int i=0;i<2;i++) (*params)[i] = R->params[i];
}


/*typedef struct AutomationEventList {
  unsigned int capacity;
  unsigned int count;
  AutomationEvent *events;
} AutomationEventList; */
DECLARE(void AutomationEventListINTO(
  AutomationEventList *R,
  unsigned int *capacity,
  unsigned int *count,
  AutomationEvent **events)){
  R->capacity = *capacity;
  R->count = *count;
  R->events = *events;
}
DECLARE(void AutomationEventListFROM(
  AutomationEventList *R,
  unsigned int *capacity,
  unsigned int *count,
  AutomationEvent **events)){
  *capacity = R->capacity;
  *count = R->count;
  *events = R->events;
}


/*typedef struct rlVertexBuffer {
  int elementCount;
  float *vertices;
  float *texcoords;
  float *normals;
  unsigned char *colors;
  unsigned int *indices;
  unsigned int vaoId;
  unsigned int vboId[5];
} rlVertexBuffer;*/
DECLARE(void rlVertexBufferINTO(
  rlVertexBuffer *R,
  int *elementCount,
  float **vertices,
  float **texcoords,
  float **normals,
  unsigned char **colors,
  unsigned int **indices,
  unsigned int *vaoId,
  unsigned int (*vboId)[4])){
  R->elementCount = *elementCount;
  R->vertices = *vertices;
  R->texcoords = *texcoords;
  R->normals = *normals;
  R->colors = *colors;
  R->indices = *indices;
  R->vaoId = *vaoId;
  for(int i=0;i<4;i++)R->vboId[i] = (*vboId)[i];
}
DECLARE(void rlVertexBufferFROM(
  rlVertexBuffer *R,
  int *elementCount,
  float **vertices,
  float **texcoords,
  float **normals,
  unsigned char **colors,
  unsigned int **indices,
  unsigned int *vaoId,
  unsigned int (*vboId)[4])){
  *elementCount = R->elementCount;
  *vertices = R->vertices;
  *texcoords = R->texcoords;
  *normals = R->normals;
  *colors = R->colors;
  *indices = R->indices;
  *vaoId = R->vaoId;
  for(int i=0;i<4;i++) (*vboId)[i] = R->vboId[i];
}


/*typedef struct rlDrawCall {
  int mode;
  int vertexCount;
  int vertexAlignment;
  unsigned int textureId;
} rlDrawCall;*/
DECLARE(void rlDrawCallINTO(
  rlDrawCall *R,
  int *mode,
  int *vertexCount,
  int *vertexAlignment)){
  R->mode = *mode;
  R->vertexCount = *vertexCount;
  R->vertexAlignment = *vertexAlignment;
}
DECLARE(void rlDrawCallFROM(
  rlDrawCall *R,
  int *mode,
  int *vertexCount,
  int *vertexAlignment)){
  *mode = R->mode;
  *vertexCount = R->vertexCount;
  *vertexAlignment = R->vertexAlignment;
}


/*typedef struct rlRenderBatch {
  int bufferCount;
  int currentBuffer;
  rlVertexBuffer *vertexBuffer;
  rlDrawCall *draws;
  int drawCounter;
  float currentDepth;
} rlRenderBatch;*/
DECLARE(void rlRenderBatchINTO(
  rlRenderBatch *R,
  int *bufferCount,
  int *currentBuffer,
  rlVertexBuffer **vertexBuffer,
  rlDrawCall **draws,
  int *drawCounter,
  float *currentDepth)){
  R->bufferCount = *bufferCount;
  R->currentBuffer = *currentBuffer;
  R->vertexBuffer = *vertexBuffer;
  R->draws = *draws;
  R->drawCounter = *drawCounter;
  R->currentDepth = *currentDepth;
}
DECLARE(void rlRenderBatchFROM(
  rlRenderBatch *R,
  int *bufferCount,
  int *currentBuffer,
  rlVertexBuffer **vertexBuffer,
  rlDrawCall **draws,
  int *drawCounter,
  float *currentDepth)){
  *bufferCount = R->bufferCount;
  *currentBuffer = R->currentBuffer;
  *vertexBuffer = R->vertexBuffer;
  *draws = R->draws;
  *drawCounter = R->drawCounter;
  *currentDepth = R->currentDepth;
}

/*typedef struct GuiStyleProp {
  unsigned short controlId;
  unsigned short propertyId;
  int propertyValue;
} GuiStyleProp;*/
DECLARE(void GuiStylePropINTO(
  GuiStyleProp *R,
  unsigned short *controlId,
  unsigned short *propertyId,
  int *propertyValue)){
  R->controlId = *controlId;
  R->propertyId = *propertyId;
  R->propertyValue = *propertyValue;
}
DECLARE(void GuiStylePropFROM(
  GuiStyleProp *R,
  unsigned short *controlId,
  unsigned short *propertyId,
  int *propertyValue)){
  *controlId = R->controlId;
  *propertyId = R->propertyId;
  *propertyValue = R->propertyValue;
}


/*typedef struct Mat2 {
  float m00;
  float m01;
  float m10;
  float m11;
} Mat2;*/
DECLARE(void Mat2INTO(
  Mat2 *R,
  float *m00,
  float *m01,
  float *m10,
  float *m11)){
  R->m00 = *m00;
  R->m01 = *m01;
  R->m10 = *m10;
  R->m11 = *m11;
}
DECLARE(void Mat2FROM(
  Mat2 *R,
  float *m00,
  float *m01,
  float *m10,
  float *m11)){
  *m00 = R->m00;
  *m01 = R->m01;
  *m10 = R->m10;
  *m11 = R->m11;
}


/*typedef struct PolygonData {
  unsigned int vertexCount;
  Vector2 positions[PHYSAC_MAX_VERTICES];
  Vector2 normals[PHYSAC_MAX_VERTICES];
} PolygonData;*/
DECLARE(void PolygonDataINTO(
  PolygonData *R,
  unsigned int *vertexCount,
  Vector2 (*positions)[PHYSAC_MAX_VERTICES],
  Vector2 (*normals)[PHYSAC_MAX_VERTICES])){
  R->vertexCount = *vertexCount;
  for(int i=0;i<PHYSAC_MAX_VERTICES;i++) R->positions[i] = (*positions)[i];
  for(int i=0;i<PHYSAC_MAX_VERTICES;i++) R->normals[i] = (*normals)[i];
}
DECLARE(void PolygonDataFROM(
  PolygonData *R,
  unsigned int *vertexCount,
  Vector2 (*positions)[PHYSAC_MAX_VERTICES],
  Vector2 (*normals)[PHYSAC_MAX_VERTICES])){
  *vertexCount = R->vertexCount;
  for(int i=0;i<PHYSAC_MAX_VERTICES;i++) (*positions)[i] = R->positions[i];
  for(int i=0;i<PHYSAC_MAX_VERTICES;i++) (*normals)[i] = R->normals[i];
}


/*typedef struct PhysicsShape {
  PhysicsShapeType type;
  PhysicsBody body;
  float radius;
  Mat2 transform;
  PolygonData vertexData;
} PhysicsShape;*/
DECLARE(void PhysicsShapeINTO(
  PhysicsShape *R,
  PhysicsShapeType *type,
  PhysicsBody *body,
  float *radius,
  Mat2 *transform,
  PolygonData *vertexData)){
  R->type = *type;
  R->body = *body;
  R->radius = *radius;
  R->transform = *transform;
  R->vertexData = *vertexData;
}
DECLARE(void PhysicsShapeFROM(
  PhysicsShape *R,
  PhysicsShapeType *type,
  PhysicsBody *body,
  float *radius,
  Mat2 *transform,
  PolygonData *vertexData)){
  *type = R->type;
  *body = R->body;
  *radius = R->radius;
  *transform = R->transform;
  *vertexData = R->vertexData;
}


/*typedef struct PhysicsBodyData {
  unsigned int id;
  bool enabled;
  Vector2 position;
  Vector2 velocity;
  Vector2 force;
  float angularVelocity;
  float torque;
  float orient;
  float inertia;
  float inverseInertia;
  float mass;
  float inverseMass;
  float staticFriction;
  float dynamicFriction;
  float restitution;
  bool useGravity;
  bool isGrounded;
  bool freezeOrient;
  PhysicsShape shape;
} PhysicsBodyData;*/
DECLARE(void PhysicsBodyDataINTO(
  PhysicsBodyData *R,
  unsigned int *id,
  bool *enabled,
  Vector2 *position,
  Vector2 *velocity,
  Vector2 *force,
  float *angularVelocity,
  float *torque,
  float *orient,
  float *inertia,
  float *inverseInertia,
  float *mass,
  float *inverseMass,
  float *staticFriction,
  float *dynamicFriction,
  float *restitution,
  bool *useGravity,
  bool *isGrounded,
  bool *freezeOrient,
  PhysicsShape *shape)){
  R->id = *id;
  R->enabled = *enabled;
  R->position = *position;
  R->velocity = *velocity;
  R->force = *force;
  R->angularVelocity = *angularVelocity;
  R->torque = *torque;
  R->orient = *orient;
  R->inertia = *inertia;
  R->inverseInertia = *inverseInertia;
  R->mass = *mass;
  R->inverseMass = *inverseMass;
  R->staticFriction = *staticFriction;
  R->dynamicFriction = *dynamicFriction;
  R->restitution = *restitution;
  R->useGravity = *useGravity;
  R->isGrounded = *isGrounded;
  R->freezeOrient = *freezeOrient;
  R->shape = *shape;
}
DECLARE(void PhysicsBodyDataFROM(
  PhysicsBodyData *R,
  unsigned int *id,
  bool *enabled,
  Vector2 *position,
  Vector2 *velocity,
  Vector2 *force,
  float *angularVelocity,
  float *torque,
  float *orient,
  float *inertia,
  float *inverseInertia,
  float *mass,
  float *inverseMass,
  float *staticFriction,
  float *dynamicFriction,
  float *restitution,
  bool *useGravity,
  bool *isGrounded,
  bool *freezeOrient,
  PhysicsShape *shape)){
  *id = R->id;
  *enabled = R->enabled;
  *position = R->position;
  *velocity = R->velocity;
  *force = R->force;
  *angularVelocity = R->angularVelocity;
  *torque = R->torque;
  *orient = R->orient;
  *inertia = R->inertia;
  *inverseInertia = R->inverseInertia;
  *mass = R->mass;
  *inverseMass = R->inverseMass;
  *staticFriction = R->staticFriction;
  *dynamicFriction = R->dynamicFriction;
  *restitution = R->restitution;
  *useGravity = R->useGravity;
  *isGrounded = R->isGrounded;
  *freezeOrient = R->freezeOrient;
  *shape = R->shape;
}


/*typedef struct PhysicsManifoldData {
  unsigned int id;
  PhysicsBody bodyA;
  PhysicsBody bodyB;
  float penetration;
  Vector2 normal;
  Vector2 contacts[2];
  unsigned int contactsCount;
  float restitution;
  float dynamicFriction;
  float staticFriction;
} PhysicsManifoldData;*/
DECLARE(void PhysicsManifoldDataINTO(
  PhysicsManifoldData *R,
  unsigned int *id,
  PhysicsBody *bodyA,
  PhysicsBody *bodyB,
  float *penetration,
  Vector2 *normal,
  Vector2 (*contacts)[2],
  unsigned int *contactsCount,
  float *restitution,
  float *dynamicFriction,
  float *staticFriction)){
  R->id = *id;
  R->bodyA = *bodyA;
  R->bodyB = *bodyB;
  R->penetration = *penetration;
  R->normal = *normal;
  for(int i=0;i<2;i++) R->contacts[i] = (*contacts)[i];
  R->contactsCount = *contactsCount;
  R->restitution = *restitution;
  R->dynamicFriction = *dynamicFriction;
  R->staticFriction = *staticFriction;
}
DECLARE(void PhysicsManifoldDataFROM(
  PhysicsManifoldData *R,
  unsigned int *id,
  PhysicsBody *bodyA,
  PhysicsBody *bodyB,
  float *penetration,
  Vector2 *normal,
  Vector2 (*contacts)[2],
  unsigned int (*contactsCount),
  float *restitution,
  float *dynamicFriction,
  float *staticFriction)){
  *id = R->id;
  *bodyA = R->bodyA;
  *bodyB = R->bodyB;
  *penetration = R->penetration;
  *normal = R->normal;
  for(int i=0;i<2;i++) (*contacts)[i] = R->contacts[i];
  *contactsCount = R->contactsCount;
  *restitution = R->restitution;
  *dynamicFriction = R->dynamicFriction;
  *staticFriction = R->staticFriction;
}
