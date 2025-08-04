#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS
#define InitTimer InitTimerPhysac
#include "physac.h"
#define InitTimer InitTimer
char *structNames[] = {"Mat2","PolygonData","PhysicsShape","PhysicsBodyData","PhysicsManifoldData","Vector2","Vector3","Vector4","Matrix","Color","Rectangle","Image","Texture","RenderTexture","NPatchInfo","GlyphInfo","Font","Camera3D","Camera2D","Mesh","Shader","MaterialMap","Material","Transform","BoneInfo","Model","ModelAnimation","Ray","RayCollision","BoundingBox","Wave","AudioStream","Sound","Music","VrDeviceInfo","VrStereoConfig","FilePathList","AutomationEvent","AutomationEventList","float3","float16","rlVertexBuffer","rlDrawCall","rlRenderBatch","GuiStyleProp",};
int structSizes[] = {sizeof(Mat2),sizeof(PolygonData),sizeof(PhysicsShape),sizeof(PhysicsBodyData),sizeof(PhysicsManifoldData),sizeof(Vector2),sizeof(Vector3),sizeof(Vector4),sizeof(Matrix),sizeof(Color),sizeof(Rectangle),sizeof(Image),sizeof(Texture),sizeof(RenderTexture),sizeof(NPatchInfo),sizeof(GlyphInfo),sizeof(Font),sizeof(Camera3D),sizeof(Camera2D),sizeof(Mesh),sizeof(Shader),sizeof(MaterialMap),sizeof(Material),sizeof(Transform),sizeof(BoneInfo),sizeof(Model),sizeof(ModelAnimation),sizeof(Ray),sizeof(RayCollision),sizeof(BoundingBox),sizeof(Wave),sizeof(AudioStream),sizeof(Sound),sizeof(Music),sizeof(VrDeviceInfo),sizeof(VrStereoConfig),sizeof(FilePathList),sizeof(AutomationEvent),sizeof(AutomationEventList),sizeof(float3),sizeof(float16),sizeof(rlVertexBuffer),sizeof(rlDrawCall),sizeof(rlRenderBatch),sizeof(GuiStyleProp),};

#include "IntoFrom.c"
#define DECLARE(x) RLAPI x; x

DECLARE(int StructCount()){return 45;}
DECLARE(int GetStructSize(int index)){return structSizes[index];}
DECLARE(void GetStructName(char *retName, int strlen, int index)){
  for (int i=0;i<strlen;i++) {
    retName[i] = structNames[index][i];
  }
}
DECLARE(int GetStructNameLength(int index)){
  char *name = structNames[index];
  int acc=0;
  while (name[acc] != '\0') acc++;
  return acc;
}
DECLARE(void memcpy2(void *x, void *y, size_t z)){memcpy(x,y,z);}
DECLARE(void strcpy2(void *x, void *y)){strcpy(x,y);}
DECLARE(void InitPhysicsRetPtr()){InitPhysics();}                                                                           // Initializes physics values, pointers and creates physics loop thread
DECLARE(void RunPhysicsStepRetPtr()){RunPhysicsStep();}                                                                        // Run physics step, to be used if PHYSICS_NO_THREADS is set in your main loop
DECLARE(void SetPhysicsTimeStepRetPtr(double *delta)){SetPhysicsTimeStep(*delta);}                                                            // Sets physics fixed time step in milliseconds. 1.666666 by default
DECLARE(void IsPhysicsEnabledRetPtr(bool *ret)){*ret=IsPhysicsEnabled();}                                                                      // Returns true if physics thread is currently enabled
DECLARE(void SetPhysicsGravityRetPtr(float *x,  float *y)){SetPhysicsGravity(*x, *y);}                                                         // Sets physics global gravity force
DECLARE(void CreatePhysicsBodyCircleRetPtr(PhysicsBody *ret, Vector2 *pos,  float *radius,  float *density)){*ret=CreatePhysicsBodyCircle(*pos, *radius, *density);}                    // Creates a new circle physics body with generic parameters
DECLARE(void CreatePhysicsBodyRectangleRetPtr(PhysicsBody *ret, Vector2 *pos,  float *width,  float *height,  float *density)){*ret=CreatePhysicsBodyRectangle(*pos, *width, *height, *density);}    // Creates a new rectangle physics body with generic parameters
DECLARE(void CreatePhysicsBodyPolygonRetPtr(PhysicsBody *ret, Vector2 *pos,  float *radius,  int *sides,  float *density)){*ret=CreatePhysicsBodyPolygon(*pos, *radius, *sides, *density);}        // Creates a new polygon physics body with generic parameters
DECLARE(void PhysicsAddForceRetPtr(PhysicsBody *body,  Vector2 *force)){PhysicsAddForce(*body, *force);}                                            // Adds a force to a physics body
DECLARE(void PhysicsAddTorqueRetPtr(PhysicsBody *body,  float *amount)){PhysicsAddTorque(*body, *amount);}                                            // Adds an angular force to a physics body
DECLARE(void PhysicsShatterRetPtr(PhysicsBody *body,  Vector2 *position,  float *force)){PhysicsShatter(*body, *position, *force);}                             // Shatters a polygon shape physics body to little physics bodies with explosion force
DECLARE(void GetPhysicsBodiesCountRetPtr(int *ret)){*ret=GetPhysicsBodiesCount();}                                                                  // Returns the current amount of created physics bodies
DECLARE(void GetPhysicsBodyRetPtr(PhysicsBody *ret, int *index)){*ret=GetPhysicsBody(*index);}                                                            // Returns a physics body of the bodies pool at a specific index
DECLARE(void GetPhysicsShapeTypeRetPtr(int *ret, int *index)){*ret=GetPhysicsShapeType(*index);}                                                               // Returns the physics body shape type (PHYSICS_CIRCLE or PHYSICS_POLYGON)
DECLARE(void GetPhysicsShapeVerticesCountRetPtr(int *ret, int *index)){*ret=GetPhysicsShapeVerticesCount(*index);}                                                      // Returns the amount of vertices of a physics body shape
DECLARE(void GetPhysicsShapeVertexRetPtr(Vector2 *ret, PhysicsBody *body,  int *vertex)){*ret=GetPhysicsShapeVertex(*body, *vertex);}                                      // Returns transformed position of a body shape (body position + vertex transformed position)
DECLARE(void SetPhysicsBodyRotationRetPtr(PhysicsBody *body,  float *radians)){SetPhysicsBodyRotation(*body, *radians);}                                     // Sets physics body shape transform based on radians parameter
DECLARE(void DestroyPhysicsBodyRetPtr(PhysicsBody *body)){DestroyPhysicsBody(*body);}                                                        // Unitializes and destroy a physics body
DECLARE(void ClosePhysicsRetPtr()){ClosePhysics();}                                                                          // Unitializes physics pointers and closes physics loop thread
DECLARE(void InitWindowRetPtr(int *width,  int *height,  const char **title)){InitWindow(*width, *height, *title);}  // Initialize window and OpenGL context
DECLARE(void CloseWindowRetPtr()){CloseWindow();}                                     // Close window and unload OpenGL context
DECLARE(void WindowShouldCloseRetPtr(bool *ret)){*ret=WindowShouldClose();}                               // Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
DECLARE(void IsWindowReadyRetPtr(bool *ret)){*ret=IsWindowReady();}                                   // Check if window has been initialized successfully
DECLARE(void IsWindowFullscreenRetPtr(bool *ret)){*ret=IsWindowFullscreen();}                              // Check if window is currently fullscreen
DECLARE(void IsWindowHiddenRetPtr(bool *ret)){*ret=IsWindowHidden();}                                  // Check if window is currently hidden
DECLARE(void IsWindowMinimizedRetPtr(bool *ret)){*ret=IsWindowMinimized();}                               // Check if window is currently minimized
DECLARE(void IsWindowMaximizedRetPtr(bool *ret)){*ret=IsWindowMaximized();}                               // Check if window is currently maximized
DECLARE(void IsWindowFocusedRetPtr(bool *ret)){*ret=IsWindowFocused();}                                 // Check if window is currently focused
DECLARE(void IsWindowResizedRetPtr(bool *ret)){*ret=IsWindowResized();}                                 // Check if window has been resized last frame
DECLARE(void IsWindowStateRetPtr(bool *ret, unsigned int *flag)){*ret=IsWindowState(*flag);}                      // Check if one specific window flag is enabled
DECLARE(void SetWindowStateRetPtr(unsigned int *flags)){SetWindowState(*flags);}                    // Set window configuration state using flags
DECLARE(void ClearWindowStateRetPtr(unsigned int *flags)){ClearWindowState(*flags);}                  // Clear window configuration state flags
DECLARE(void ToggleFullscreenRetPtr()){ToggleFullscreen();}                                // Toggle window state: fullscreen/windowed, resizes monitor to match window resolution
DECLARE(void ToggleBorderlessWindowedRetPtr()){ToggleBorderlessWindowed();}                        // Toggle window state: borderless windowed, resizes window to match monitor resolution
DECLARE(void MaximizeWindowRetPtr()){MaximizeWindow();}                                  // Set window state: maximized, if resizable
DECLARE(void MinimizeWindowRetPtr()){MinimizeWindow();}                                  // Set window state: minimized, if resizable
DECLARE(void RestoreWindowRetPtr()){RestoreWindow();}                                   // Set window state: not minimized/maximized
DECLARE(void SetWindowIconRetPtr(Image *image)){SetWindowIcon(*image);}                            // Set icon for window (single image, RGBA 32bit)
DECLARE(void SetWindowIconsRetPtr(Image **images,  int *count)){SetWindowIcons(*images, *count);}              // Set icon for window (multiple images, RGBA 32bit)
DECLARE(void SetWindowTitleRetPtr(const char **title)){SetWindowTitle(*title);}                     // Set title for window
DECLARE(void SetWindowPositionRetPtr(int *x,  int *y)){SetWindowPosition(*x, *y);}                       // Set window position on screen
DECLARE(void SetWindowMonitorRetPtr(int *monitor)){SetWindowMonitor(*monitor);}                         // Set monitor for the current window
DECLARE(void SetWindowMinSizeRetPtr(int *width,  int *height)){SetWindowMinSize(*width, *height);}               // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
DECLARE(void SetWindowMaxSizeRetPtr(int *width,  int *height)){SetWindowMaxSize(*width, *height);}               // Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)
DECLARE(void SetWindowSizeRetPtr(int *width,  int *height)){SetWindowSize(*width, *height);}                  // Set window dimensions
DECLARE(void SetWindowOpacityRetPtr(float *opacity)){SetWindowOpacity(*opacity);}                       // Set window opacity [0.0f..1.0f]
DECLARE(void SetWindowFocusedRetPtr()){SetWindowFocused();}                                // Set window focused
DECLARE(void GetWindowHandleRetPtr(void **ret)){*ret=GetWindowHandle();}                                // Get native window handle
DECLARE(void GetScreenWidthRetPtr(int *ret)){*ret=GetScreenWidth();}                                   // Get current screen width
DECLARE(void GetScreenHeightRetPtr(int *ret)){*ret=GetScreenHeight();}                                  // Get current screen height
DECLARE(void GetRenderWidthRetPtr(int *ret)){*ret=GetRenderWidth();}                                   // Get current render width (it considers HiDPI)
DECLARE(void GetRenderHeightRetPtr(int *ret)){*ret=GetRenderHeight();}                                  // Get current render height (it considers HiDPI)
DECLARE(void GetMonitorCountRetPtr(int *ret)){*ret=GetMonitorCount();}                                  // Get number of connected monitors
DECLARE(void GetCurrentMonitorRetPtr(int *ret)){*ret=GetCurrentMonitor();}                                // Get current monitor where window is placed
DECLARE(void GetMonitorPositionRetPtr(Vector2 *ret, int *monitor)){*ret=GetMonitorPosition(*monitor);}                    // Get specified monitor position
DECLARE(void GetMonitorWidthRetPtr(int *ret, int *monitor)){*ret=GetMonitorWidth(*monitor);}                           // Get specified monitor width (current video mode used by monitor)
DECLARE(void GetMonitorHeightRetPtr(int *ret, int *monitor)){*ret=GetMonitorHeight(*monitor);}                          // Get specified monitor height (current video mode used by monitor)
DECLARE(void GetMonitorPhysicalWidthRetPtr(int *ret, int *monitor)){*ret=GetMonitorPhysicalWidth(*monitor);}                   // Get specified monitor physical width in millimetres
DECLARE(void GetMonitorPhysicalHeightRetPtr(int *ret, int *monitor)){*ret=GetMonitorPhysicalHeight(*monitor);}                  // Get specified monitor physical height in millimetres
DECLARE(void GetMonitorRefreshRateRetPtr(int *ret, int *monitor)){*ret=GetMonitorRefreshRate(*monitor);}                     // Get specified monitor refresh rate
DECLARE(void GetWindowPositionRetPtr(Vector2 *ret)){*ret=GetWindowPosition();}                            // Get window position XY on monitor
DECLARE(void GetWindowScaleDPIRetPtr(Vector2 *ret)){*ret=GetWindowScaleDPI();}                            // Get window scale DPI factor
DECLARE(void GetMonitorNameRetPtr(const char **ret, int *monitor)){*ret=GetMonitorName(*monitor);}                    // Get the human-readable, UTF-8 encoded name of the specified monitor
DECLARE(void SetClipboardTextRetPtr(const char **text)){SetClipboardText(*text);}                    // Set clipboard text content
DECLARE(void GetClipboardTextRetPtr(const char **ret)){*ret=GetClipboardText();}                         // Get clipboard text content
DECLARE(void GetClipboardImageRetPtr(Image *ret)){*ret=GetClipboardImage();}                              // Get clipboard image content
DECLARE(void EnableEventWaitingRetPtr()){EnableEventWaiting();}                              // Enable waiting for events on EndDrawing(), no automatic event polling
DECLARE(void DisableEventWaitingRetPtr()){DisableEventWaiting();}                             // Disable waiting for events on EndDrawing(), automatic events polling
DECLARE(void ShowCursorRetPtr()){ShowCursor();}                                      // Shows cursor
DECLARE(void HideCursorRetPtr()){HideCursor();}                                      // Hides cursor
DECLARE(void IsCursorHiddenRetPtr(bool *ret)){*ret=IsCursorHidden();}                                  // Check if cursor is not visible
DECLARE(void EnableCursorRetPtr()){EnableCursor();}                                    // Enables cursor (unlock cursor)
DECLARE(void DisableCursorRetPtr()){DisableCursor();}                                   // Disables cursor (lock cursor)
DECLARE(void IsCursorOnScreenRetPtr(bool *ret)){*ret=IsCursorOnScreen();}                                // Check if cursor is on the screen
DECLARE(void ClearBackgroundRetPtr(Color *color)){ClearBackground(*color);}                          // Set background color (framebuffer clear color)
DECLARE(void BeginDrawingRetPtr()){BeginDrawing();}                                    // Setup canvas (framebuffer) to start drawing
DECLARE(void EndDrawingRetPtr()){EndDrawing();}                                      // End canvas drawing and swap buffers (double buffering)
DECLARE(void BeginMode2DRetPtr(Camera2D *camera)){BeginMode2D(*camera);}                          // Begin 2D mode with custom camera (2D)
DECLARE(void EndMode2DRetPtr()){EndMode2D();}                                       // Ends 2D mode with custom camera
DECLARE(void BeginMode3DRetPtr(Camera3D *camera)){BeginMode3D(*camera);}                          // Begin 3D mode with custom camera (3D)
DECLARE(void EndMode3DRetPtr()){EndMode3D();}                                       // Ends 3D mode and returns to default 2D orthographic mode
DECLARE(void BeginTextureModeRetPtr(RenderTexture2D *target)){BeginTextureMode(*target);}              // Begin drawing to render texture
DECLARE(void EndTextureModeRetPtr()){EndTextureMode();}                                  // Ends drawing to render texture
DECLARE(void BeginShaderModeRetPtr(Shader *shader)){BeginShaderMode(*shader);}                        // Begin custom shader drawing
DECLARE(void EndShaderModeRetPtr()){EndShaderMode();}                                   // End custom shader drawing (use default shader)
DECLARE(void BeginBlendModeRetPtr(int *mode)){BeginBlendMode(*mode);}                              // Begin blending mode (alpha, additive, multiplied, subtract, custom)
DECLARE(void EndBlendModeRetPtr()){EndBlendMode();}                                    // End blending mode (reset to default: alpha blending)
DECLARE(void BeginScissorModeRetPtr(int *x,  int *y,  int *width,  int *height)){BeginScissorMode(*x, *y, *width, *height);} // Begin scissor mode (define screen area for following drawing)
DECLARE(void EndScissorModeRetPtr()){EndScissorMode();}                                  // End scissor mode
DECLARE(void BeginVrStereoModeRetPtr(VrStereoConfig *config)){BeginVrStereoMode(*config);}              // Begin stereo rendering (requires VR simulator)
DECLARE(void EndVrStereoModeRetPtr()){EndVrStereoMode();}                                 // End stereo rendering (requires VR simulator)
DECLARE(void LoadVrStereoConfigRetPtr(VrStereoConfig *ret, VrDeviceInfo *device)){*ret=LoadVrStereoConfig(*device);}     // Load VR stereo config for VR simulator device parameters
DECLARE(void UnloadVrStereoConfigRetPtr(VrStereoConfig *config)){UnloadVrStereoConfig(*config);}           // Unload VR stereo config
DECLARE(void LoadShaderRetPtr(Shader *ret, const char **vsFileName,  const char **fsFileName)){*ret=LoadShader(*vsFileName, *fsFileName);}   // Load shader from files and bind default locations
DECLARE(void LoadShaderFromMemoryRetPtr(Shader *ret, const char **vsCode,  const char **fsCode)){*ret=LoadShaderFromMemory(*vsCode, *fsCode);} // Load shader from code strings and bind default locations
DECLARE(void IsShaderValidRetPtr(bool *ret, Shader *shader)){*ret=IsShaderValid(*shader);}                                   // Check if a shader is valid (loaded on GPU)
DECLARE(void GetShaderLocationRetPtr(int *ret, Shader *shader,  const char **uniformName)){*ret=GetShaderLocation(*shader, *uniformName);}       // Get shader uniform location
DECLARE(void GetShaderLocationAttribRetPtr(int *ret, Shader *shader,  const char **attribName)){*ret=GetShaderLocationAttrib(*shader, *attribName);}  // Get shader attribute location
DECLARE(void SetShaderValueRetPtr(Shader *shader,  int *locIndex,  const void **value,  int *uniformType)){SetShaderValue(*shader, *locIndex, *value, *uniformType);}               // Set shader uniform value
DECLARE(void SetShaderValueVRetPtr(Shader *shader,  int *locIndex,  const void **value,  int *uniformType,  int *count)){SetShaderValueV(*shader, *locIndex, *value, *uniformType, *count);}   // Set shader uniform value vector
DECLARE(void SetShaderValueMatrixRetPtr(Shader *shader,  int *locIndex,  Matrix *mat)){SetShaderValueMatrix(*shader, *locIndex, *mat);}         // Set shader uniform value (matrix 4x4)
DECLARE(void SetShaderValueTextureRetPtr(Shader *shader,  int *locIndex,  Texture2D *texture)){SetShaderValueTexture(*shader, *locIndex, *texture);} // Set shader uniform value for texture (sampler2d)
DECLARE(void UnloadShaderRetPtr(Shader *shader)){UnloadShader(*shader);}                                    // Unload shader from GPU memory (VRAM)
DECLARE(void GetScreenToWorldRayRetPtr(Ray *ret, Vector2 *position,  Camera *camera)){*ret=GetScreenToWorldRay(*position, *camera);}         // Get a ray trace from screen position (i.e mouse)
DECLARE(void GetScreenToWorldRayExRetPtr(Ray *ret, Vector2 *position,  Camera *camera,  int *width,  int *height)){*ret=GetScreenToWorldRayEx(*position, *camera, *width, *height);} // Get a ray trace from screen position (i.e mouse) in a viewport
DECLARE(void GetWorldToScreenRetPtr(Vector2 *ret, Vector3 *position,  Camera *camera)){*ret=GetWorldToScreen(*position, *camera);}        // Get the screen space position for a 3d world space position
DECLARE(void GetWorldToScreenExRetPtr(Vector2 *ret, Vector3 *position,  Camera *camera,  int *width,  int *height)){*ret=GetWorldToScreenEx(*position, *camera, *width, *height);} // Get size position for a 3d world space position
DECLARE(void GetWorldToScreen2DRetPtr(Vector2 *ret, Vector2 *position,  Camera2D *camera)){*ret=GetWorldToScreen2D(*position, *camera);}    // Get the screen space position for a 2d camera world space position
DECLARE(void GetScreenToWorld2DRetPtr(Vector2 *ret, Vector2 *position,  Camera2D *camera)){*ret=GetScreenToWorld2D(*position, *camera);}    // Get the world space position for a 2d camera screen space position
DECLARE(void GetCameraMatrixRetPtr(Matrix *ret, Camera *camera)){*ret=GetCameraMatrix(*camera);}                            // Get camera transform matrix (view matrix)
DECLARE(void GetCameraMatrix2DRetPtr(Matrix *ret, Camera2D *camera)){*ret=GetCameraMatrix2D(*camera);}                        // Get camera 2d transform matrix
DECLARE(void SetTargetFPSRetPtr(int *fps)){SetTargetFPS(*fps);}                                 // Set target FPS (maximum)
DECLARE(void GetFrameTimeRetPtr(float *ret)){*ret=GetFrameTime();}                                   // Get time in seconds for last frame drawn (delta time)
DECLARE(void GetTimeRetPtr(double *ret)){*ret=GetTime();}                                       // Get elapsed time in seconds since InitWindow()
DECLARE(void GetFPSRetPtr(int *ret)){*ret=GetFPS();}                                           // Get current FPS
DECLARE(void SwapScreenBufferRetPtr()){SwapScreenBuffer();}                                // Swap back buffer with front buffer (screen drawing)
DECLARE(void PollInputEventsRetPtr()){PollInputEvents();}                                 // Register all input events
DECLARE(void WaitTimeRetPtr(double *seconds)){WaitTime(*seconds);}                              // Wait for some time (halt program execution)
DECLARE(void SetRandomSeedRetPtr(unsigned int *seed)){SetRandomSeed(*seed);}                      // Set the seed for the random number generator
DECLARE(void GetRandomValueRetPtr(int *ret, int *min,  int *max)){*ret=GetRandomValue(*min, *max);}                       // Get a random value between min and max (both included)
DECLARE(void LoadRandomSequenceRetPtr(int **ret, unsigned int *count,  int *min,  int *max)){*ret=LoadRandomSequence(*count, *min, *max);} // Load random values sequence, no values repeated
DECLARE(void UnloadRandomSequenceRetPtr(int **sequence)){UnloadRandomSequence(*sequence);}                   // Unload random values sequence
DECLARE(void TakeScreenshotRetPtr(const char **fileName)){TakeScreenshot(*fileName);}                  // Takes a screenshot of current screen (filename extension defines format)
DECLARE(void SetConfigFlagsRetPtr(unsigned int *flags)){SetConfigFlags(*flags);}                    // Setup init configuration flags (view FLAGS)
DECLARE(void OpenURLRetPtr(const char **url)){OpenURL(*url);}                              // Open URL with default system browser (if available)
DECLARE(void TraceLogRetPtr(int *logLevel,  const char **text,  void **args)){TraceLog(*logLevel, *text, *args);}         // Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
DECLARE(void SetTraceLogLevelRetPtr(int *logLevel)){SetTraceLogLevel(*logLevel);}                        // Set the current threshold (minimum) log level
DECLARE(void MemAllocRetPtr(void **ret, unsigned int *size)){*ret=MemAlloc(*size);}                          // Internal memory allocator
DECLARE(void MemReallocRetPtr(void **ret, void **ptr,  unsigned int *size)){*ret=MemRealloc(*ptr, *size);}             // Internal memory reallocator
DECLARE(void MemFreeRetPtr(void **ptr)){MemFree(*ptr);}                                    // Internal memory free
DECLARE(void SetTraceLogCallbackRetPtr(TraceLogCallback *callback)){SetTraceLogCallback(*callback);}         // Set custom trace log
DECLARE(void SetLoadFileDataCallbackRetPtr(LoadFileDataCallback *callback)){SetLoadFileDataCallback(*callback);} // Set custom file binary data loader
DECLARE(void SetSaveFileDataCallbackRetPtr(SaveFileDataCallback *callback)){SetSaveFileDataCallback(*callback);} // Set custom file binary data saver
DECLARE(void SetLoadFileTextCallbackRetPtr(LoadFileTextCallback *callback)){SetLoadFileTextCallback(*callback);} // Set custom file text data loader
DECLARE(void SetSaveFileTextCallbackRetPtr(SaveFileTextCallback *callback)){SetSaveFileTextCallback(*callback);} // Set custom file text data saver
DECLARE(void LoadFileDataRetPtr(unsigned char **ret, const char **fileName,  int **dataSize)){*ret=LoadFileData(*fileName, *dataSize);} // Load file data as byte array (read)
DECLARE(void UnloadFileDataRetPtr(unsigned char **data)){UnloadFileData(*data);}                   // Unload file data allocated by LoadFileData()
DECLARE(void SaveFileDataRetPtr(bool *ret, const char **fileName,  void **data,  int *dataSize)){*ret=SaveFileData(*fileName, *data, *dataSize);} // Save data to file from byte array (write), returns true on success
DECLARE(void ExportDataAsCodeRetPtr(bool *ret, const unsigned char **data,  int *dataSize,  const char **fileName)){*ret=ExportDataAsCode(*data, *dataSize, *fileName);} // Export data to code (.h), returns true on success
DECLARE(void LoadFileTextRetPtr(char **ret, const char **fileName)){*ret=LoadFileText(*fileName);}                   // Load text data from file (read), returns a '\0' terminated string
DECLARE(void UnloadFileTextRetPtr(char **text)){UnloadFileText(*text);}                            // Unload file text data allocated by LoadFileText()
DECLARE(void SaveFileTextRetPtr(bool *ret, const char **fileName,  char **text)){*ret=SaveFileText(*fileName, *text);}        // Save text data to file (write), string must be '\0' terminated, returns true on success
DECLARE(void FileExistsRetPtr(bool *ret, const char **fileName)){*ret=FileExists(*fileName);}                      // Check if file exists
DECLARE(void DirectoryExistsRetPtr(bool *ret, const char **dirPath)){*ret=DirectoryExists(*dirPath);}                  // Check if a directory path exists
DECLARE(void IsFileExtensionRetPtr(bool *ret, const char **fileName,  const char **ext)){*ret=IsFileExtension(*fileName, *ext);} // Check file extension (including point: .png, .wav)
DECLARE(void GetFileLengthRetPtr(int *ret, const char **fileName)){*ret=GetFileLength(*fileName);}                    // Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
DECLARE(void GetFileExtensionRetPtr(const char **ret, const char **fileName)){*ret=GetFileExtension(*fileName);}         // Get pointer to extension for a filename string (includes dot: '.png')
DECLARE(void GetFileNameRetPtr(const char **ret, const char **filePath)){*ret=GetFileName(*filePath);}              // Get pointer to filename for a path string
DECLARE(void GetFileNameWithoutExtRetPtr(const char **ret, const char **filePath)){*ret=GetFileNameWithoutExt(*filePath);}    // Get filename string without extension (uses static string)
DECLARE(void GetDirectoryPathRetPtr(const char **ret, const char **filePath)){*ret=GetDirectoryPath(*filePath);}         // Get full path for a given fileName with path (uses static string)
DECLARE(void GetPrevDirectoryPathRetPtr(const char **ret, const char **dirPath)){*ret=GetPrevDirectoryPath(*dirPath);}      // Get previous directory path for a given path (uses static string)
DECLARE(void GetWorkingDirectoryRetPtr(const char **ret)){*ret=GetWorkingDirectory();}                      // Get current working directory (uses static string)
DECLARE(void GetApplicationDirectoryRetPtr(const char **ret)){*ret=GetApplicationDirectory();}                  // Get the directory of the running application (uses static string)
DECLARE(void MakeDirectoryRetPtr(int *ret, const char **dirPath)){*ret=MakeDirectory(*dirPath);}                     // Create directories (including full path requested), returns 0 on success
DECLARE(void ChangeDirectoryRetPtr(bool *ret, const char **dir)){*ret=ChangeDirectory(*dir);}                      // Change working directory, return true on success
DECLARE(void IsPathFileRetPtr(bool *ret, const char **path)){*ret=IsPathFile(*path);}                          // Check if a given path is a file or a directory
DECLARE(void IsFileNameValidRetPtr(bool *ret, const char **fileName)){*ret=IsFileNameValid(*fileName);}                 // Check if fileName is valid for the platform/OS
DECLARE(void LoadDirectoryFilesRetPtr(FilePathList *ret, const char **dirPath)){*ret=LoadDirectoryFiles(*dirPath);}       // Load directory filepaths
DECLARE(void LoadDirectoryFilesExRetPtr(FilePathList *ret, const char **basePath,  const char **filter,  bool *scanSubdirs)){*ret=LoadDirectoryFilesEx(*basePath, *filter, *scanSubdirs);} // Load directory filepaths with extension filtering and recursive directory scan. Use 'DIR' in the filter string to include directories in the result
DECLARE(void UnloadDirectoryFilesRetPtr(FilePathList *files)){UnloadDirectoryFiles(*files);}              // Unload filepaths
DECLARE(void IsFileDroppedRetPtr(bool *ret)){*ret=IsFileDropped();}                                   // Check if a file has been dropped into window
DECLARE(void LoadDroppedFilesRetPtr(FilePathList *ret)){*ret=LoadDroppedFiles();}                        // Load dropped filepaths
DECLARE(void UnloadDroppedFilesRetPtr(FilePathList *files)){UnloadDroppedFiles(*files);}                // Unload dropped filepaths
DECLARE(void GetFileModTimeRetPtr(long *ret, const char **fileName)){*ret=GetFileModTime(*fileName);}                  // Get file modification time (last write time)
DECLARE(void CompressDataRetPtr(unsigned char **ret, const unsigned char **data,  int *dataSize,  int **compDataSize)){*ret=CompressData(*data, *dataSize, *compDataSize);}        // Compress data (DEFLATE algorithm), memory must be MemFree()
DECLARE(void DecompressDataRetPtr(unsigned char **ret, const unsigned char **compData,  int *compDataSize,  int **dataSize)){*ret=DecompressData(*compData, *compDataSize, *dataSize);}  // Decompress data (DEFLATE algorithm), memory must be MemFree()
DECLARE(void EncodeDataBase64RetPtr(char **ret, const unsigned char **data,  int *dataSize,  int **outputSize)){*ret=EncodeDataBase64(*data, *dataSize, *outputSize);}               // Encode data to Base64 string, memory must be MemFree()
DECLARE(void DecodeDataBase64RetPtr(unsigned char **ret, const unsigned char **data,  int **outputSize)){*ret=DecodeDataBase64(*data, *outputSize);}                    // Decode Base64 string data, memory must be MemFree()
DECLARE(void ComputeCRC32RetPtr(unsigned int *ret, unsigned char **data,  int *dataSize)){*ret=ComputeCRC32(*data, *dataSize);}     // Compute CRC32 hash code
DECLARE(void ComputeMD5RetPtr(unsigned int **ret, unsigned char **data,  int *dataSize)){*ret=ComputeMD5(*data, *dataSize);}      // Compute MD5 hash code, returns static int[4] (16 bytes)
DECLARE(void ComputeSHA1RetPtr(unsigned int **ret, unsigned char **data,  int *dataSize)){*ret=ComputeSHA1(*data, *dataSize);}      // Compute SHA1 hash code, returns static int[5] (20 bytes)
DECLARE(void LoadAutomationEventListRetPtr(AutomationEventList *ret, const char **fileName)){*ret=LoadAutomationEventList(*fileName);}                // Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS
DECLARE(void UnloadAutomationEventListRetPtr(AutomationEventList *list)){UnloadAutomationEventList(*list);}                         // Unload automation events list from file
DECLARE(void ExportAutomationEventListRetPtr(bool *ret, AutomationEventList *list,  const char **fileName)){*ret=ExportAutomationEventList(*list, *fileName);}   // Export automation events list as text file
DECLARE(void SetAutomationEventListRetPtr(AutomationEventList **list)){SetAutomationEventList(*list);}                           // Set automation event list to record to
DECLARE(void SetAutomationEventBaseFrameRetPtr(int *frame)){SetAutomationEventBaseFrame(*frame);}                                      // Set automation event internal base frame to start recording
DECLARE(void StartAutomationEventRecordingRetPtr()){StartAutomationEventRecording();}                                         // Start recording automation events (AutomationEventList must be set)
DECLARE(void StopAutomationEventRecordingRetPtr()){StopAutomationEventRecording();}                                          // Stop recording automation events
DECLARE(void PlayAutomationEventRetPtr(AutomationEvent *event)){PlayAutomationEvent(*event);}                                  // Play a recorded automation event
DECLARE(void IsKeyPressedRetPtr(bool *ret, int *key)){*ret=IsKeyPressed(*key);}                             // Check if a key has been pressed once
DECLARE(void IsKeyPressedRepeatRetPtr(bool *ret, int *key)){*ret=IsKeyPressedRepeat(*key);}                       // Check if a key has been pressed again
DECLARE(void IsKeyDownRetPtr(bool *ret, int *key)){*ret=IsKeyDown(*key);}                                // Check if a key is being pressed
DECLARE(void IsKeyReleasedRetPtr(bool *ret, int *key)){*ret=IsKeyReleased(*key);}                            // Check if a key has been released once
DECLARE(void IsKeyUpRetPtr(bool *ret, int *key)){*ret=IsKeyUp(*key);}                                  // Check if a key is NOT being pressed
DECLARE(void GetKeyPressedRetPtr(int *ret)){*ret=GetKeyPressed();}                                // Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
DECLARE(void GetCharPressedRetPtr(int *ret)){*ret=GetCharPressed();}                               // Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
DECLARE(void SetExitKeyRetPtr(int *key)){SetExitKey(*key);}                               // Set a custom key to exit program (default is ESC)
DECLARE(void IsGamepadAvailableRetPtr(bool *ret, int *gamepad)){*ret=IsGamepadAvailable(*gamepad);}                                        // Check if a gamepad is available
DECLARE(void GetGamepadNameRetPtr(const char **ret, int *gamepad)){*ret=GetGamepadName(*gamepad);}                                     // Get gamepad internal name id
DECLARE(void IsGamepadButtonPressedRetPtr(bool *ret, int *gamepad,  int *button)){*ret=IsGamepadButtonPressed(*gamepad, *button);}                        // Check if a gamepad button has been pressed once
DECLARE(void IsGamepadButtonDownRetPtr(bool *ret, int *gamepad,  int *button)){*ret=IsGamepadButtonDown(*gamepad, *button);}                           // Check if a gamepad button is being pressed
DECLARE(void IsGamepadButtonReleasedRetPtr(bool *ret, int *gamepad,  int *button)){*ret=IsGamepadButtonReleased(*gamepad, *button);}                       // Check if a gamepad button has been released once
DECLARE(void IsGamepadButtonUpRetPtr(bool *ret, int *gamepad,  int *button)){*ret=IsGamepadButtonUp(*gamepad, *button);}                             // Check if a gamepad button is NOT being pressed
DECLARE(void GetGamepadButtonPressedRetPtr(int *ret)){*ret=GetGamepadButtonPressed();}                                           // Get the last gamepad button pressed
DECLARE(void GetGamepadAxisCountRetPtr(int *ret, int *gamepad)){*ret=GetGamepadAxisCount(*gamepad);}                                        // Get gamepad axis count for a gamepad
DECLARE(void GetGamepadAxisMovementRetPtr(float *ret, int *gamepad,  int *axis)){*ret=GetGamepadAxisMovement(*gamepad, *axis);}                         // Get axis movement value for a gamepad axis
DECLARE(void SetGamepadMappingsRetPtr(int *ret, const char **mappings)){*ret=SetGamepadMappings(*mappings);}                                // Set internal gamepad mappings (SDL_GameControllerDB)
DECLARE(void SetGamepadVibrationRetPtr(int *gamepad,  float *leftMotor,  float *rightMotor,  float *duration)){SetGamepadVibration(*gamepad, *leftMotor, *rightMotor, *duration);} // Set gamepad vibration for both motors (duration in seconds)
DECLARE(void IsMouseButtonPressedRetPtr(bool *ret, int *button)){*ret=IsMouseButtonPressed(*button);}                  // Check if a mouse button has been pressed once
DECLARE(void IsMouseButtonDownRetPtr(bool *ret, int *button)){*ret=IsMouseButtonDown(*button);}                     // Check if a mouse button is being pressed
DECLARE(void IsMouseButtonReleasedRetPtr(bool *ret, int *button)){*ret=IsMouseButtonReleased(*button);}                 // Check if a mouse button has been released once
DECLARE(void IsMouseButtonUpRetPtr(bool *ret, int *button)){*ret=IsMouseButtonUp(*button);}                       // Check if a mouse button is NOT being pressed
DECLARE(void GetMouseXRetPtr(int *ret)){*ret=GetMouseX();}                                    // Get mouse position X
DECLARE(void GetMouseYRetPtr(int *ret)){*ret=GetMouseY();}                                    // Get mouse position Y
DECLARE(void GetMousePositionRetPtr(Vector2 *ret)){*ret=GetMousePosition();}                         // Get mouse position XY
DECLARE(void GetMouseDeltaRetPtr(Vector2 *ret)){*ret=GetMouseDelta();}                            // Get mouse delta between frames
DECLARE(void SetMousePositionRetPtr(int *x,  int *y)){SetMousePosition(*x, *y);}                    // Set mouse position XY
DECLARE(void SetMouseOffsetRetPtr(int *offsetX,  int *offsetY)){SetMouseOffset(*offsetX, *offsetY);}          // Set mouse offset
DECLARE(void SetMouseScaleRetPtr(float *scaleX,  float *scaleY)){SetMouseScale(*scaleX, *scaleY);}         // Set mouse scaling
DECLARE(void GetMouseWheelMoveRetPtr(float *ret)){*ret=GetMouseWheelMove();}                          // Get mouse wheel movement for X or Y, whichever is larger
DECLARE(void GetMouseWheelMoveVRetPtr(Vector2 *ret)){*ret=GetMouseWheelMoveV();}                       // Get mouse wheel movement for both X and Y
DECLARE(void SetMouseCursorRetPtr(int *cursor)){SetMouseCursor(*cursor);}                        // Set mouse cursor
DECLARE(void GetTouchXRetPtr(int *ret)){*ret=GetTouchX();}                                    // Get touch position X for touch point 0 (relative to screen size)
DECLARE(void GetTouchYRetPtr(int *ret)){*ret=GetTouchY();}                                    // Get touch position Y for touch point 0 (relative to screen size)
DECLARE(void GetTouchPositionRetPtr(Vector2 *ret, int *index)){*ret=GetTouchPosition(*index);}                    // Get touch position XY for a touch point index (relative to screen size)
DECLARE(void GetTouchPointIdRetPtr(int *ret, int *index)){*ret=GetTouchPointId(*index);}                         // Get touch point identifier for given index
DECLARE(void GetTouchPointCountRetPtr(int *ret)){*ret=GetTouchPointCount();}                           // Get number of touch points
DECLARE(void SetGesturesEnabledRetPtr(unsigned int *flags)){SetGesturesEnabled(*flags);}      // Enable a set of gestures using flags
DECLARE(void IsGestureDetectedRetPtr(bool *ret, unsigned int *gesture)){*ret=IsGestureDetected(*gesture);}     // Check if a gesture have been detected
DECLARE(void GetGestureDetectedRetPtr(int *ret)){*ret=GetGestureDetected();}                     // Get latest detected gesture
DECLARE(void GetGestureHoldDurationRetPtr(float *ret)){*ret=GetGestureHoldDuration();}               // Get gesture hold time in seconds
DECLARE(void GetGestureDragVectorRetPtr(Vector2 *ret)){*ret=GetGestureDragVector();}               // Get gesture drag vector
DECLARE(void GetGestureDragAngleRetPtr(float *ret)){*ret=GetGestureDragAngle();}                  // Get gesture drag angle
DECLARE(void GetGesturePinchVectorRetPtr(Vector2 *ret)){*ret=GetGesturePinchVector();}              // Get gesture pinch delta
DECLARE(void GetGesturePinchAngleRetPtr(float *ret)){*ret=GetGesturePinchAngle();}                 // Get gesture pinch angle
DECLARE(void UpdateCameraRetPtr(Camera **camera,  int *mode)){UpdateCamera(*camera, *mode);}      // Update camera position for selected mode
DECLARE(void UpdateCameraProRetPtr(Camera **camera,  Vector3 *movement,  Vector3 *rotation,  float *zoom)){UpdateCameraPro(*camera, *movement, *rotation, *zoom);} // Update camera movement/rotation
DECLARE(void SetShapesTextureRetPtr(Texture2D *texture,  Rectangle *source)){SetShapesTexture(*texture, *source);}       // Set texture and rectangle to be used on shapes drawing
DECLARE(void GetShapesTextureRetPtr(Texture2D *ret)){*ret=GetShapesTexture();}                                 // Get texture that is used for shapes drawing
DECLARE(void GetShapesTextureRectangleRetPtr(Rectangle *ret)){*ret=GetShapesTextureRectangle();}                        // Get texture source rectangle that is used for shapes drawing
DECLARE(void DrawPixelRetPtr(int *posX,  int *posY,  Color *color)){DrawPixel(*posX, *posY, *color);}                                                   // Draw a pixel using geometry [Can be slow, use with care]
DECLARE(void DrawPixelVRetPtr(Vector2 *position,  Color *color)){DrawPixelV(*position, *color);}                                                    // Draw a pixel using geometry (Vector version) [Can be slow, use with care]
DECLARE(void DrawLineRetPtr(int *startPosX,  int *startPosY,  int *endPosX,  int *endPosY,  Color *color)){DrawLine(*startPosX, *startPosY, *endPosX, *endPosY, *color);}                // Draw a line
DECLARE(void DrawLineVRetPtr(Vector2 *startPos,  Vector2 *endPos,  Color *color)){DrawLineV(*startPos, *endPos, *color);}                                     // Draw a line (using gl lines)
DECLARE(void DrawLineExRetPtr(Vector2 *startPos,  Vector2 *endPos,  float *thick,  Color *color)){DrawLineEx(*startPos, *endPos, *thick, *color);}                       // Draw a line (using triangles/quads)
DECLARE(void DrawLineStripRetPtr(const Vector2 **points,  int *pointCount,  Color *color)){DrawLineStrip(*points, *pointCount, *color);}                            // Draw lines sequence (using gl lines)
DECLARE(void DrawLineBezierRetPtr(Vector2 *startPos,  Vector2 *endPos,  float *thick,  Color *color)){DrawLineBezier(*startPos, *endPos, *thick, *color);}                   // Draw line segment cubic-bezier in-out interpolation
DECLARE(void DrawCircleRetPtr(int *centerX,  int *centerY,  float *radius,  Color *color)){DrawCircle(*centerX, *centerY, *radius, *color);}                              // Draw a color-filled circle
DECLARE(void DrawCircleSectorRetPtr(Vector2 *center,  float *radius,  float *startAngle,  float *endAngle,  int *segments,  Color *color)){DrawCircleSector(*center, *radius, *startAngle, *endAngle, *segments, *color);}      // Draw a piece of a circle
DECLARE(void DrawCircleSectorLinesRetPtr(Vector2 *center,  float *radius,  float *startAngle,  float *endAngle,  int *segments,  Color *color)){DrawCircleSectorLines(*center, *radius, *startAngle, *endAngle, *segments, *color);} // Draw circle sector outline
DECLARE(void DrawCircleGradientRetPtr(int *centerX,  int *centerY,  float *radius,  Color *inner,  Color *outer)){DrawCircleGradient(*centerX, *centerY, *radius, *inner, *outer);}         // Draw a gradient-filled circle
DECLARE(void DrawCircleVRetPtr(Vector2 *center,  float *radius,  Color *color)){DrawCircleV(*center, *radius, *color);}                                       // Draw a color-filled circle (Vector version)
DECLARE(void DrawCircleLinesRetPtr(int *centerX,  int *centerY,  float *radius,  Color *color)){DrawCircleLines(*centerX, *centerY, *radius, *color);}                         // Draw circle outline
DECLARE(void DrawCircleLinesVRetPtr(Vector2 *center,  float *radius,  Color *color)){DrawCircleLinesV(*center, *radius, *color);}                                  // Draw circle outline (Vector version)
DECLARE(void DrawEllipseRetPtr(int *centerX,  int *centerY,  float *radiusH,  float *radiusV,  Color *color)){DrawEllipse(*centerX, *centerY, *radiusH, *radiusV, *color);}             // Draw ellipse
DECLARE(void DrawEllipseLinesRetPtr(int *centerX,  int *centerY,  float *radiusH,  float *radiusV,  Color *color)){DrawEllipseLines(*centerX, *centerY, *radiusH, *radiusV, *color);}        // Draw ellipse outline
DECLARE(void DrawRingRetPtr(Vector2 *center,  float *innerRadius,  float *outerRadius,  float *startAngle,  float *endAngle,  int *segments,  Color *color)){DrawRing(*center, *innerRadius, *outerRadius, *startAngle, *endAngle, *segments, *color);} // Draw ring
DECLARE(void DrawRingLinesRetPtr(Vector2 *center,  float *innerRadius,  float *outerRadius,  float *startAngle,  float *endAngle,  int *segments,  Color *color)){DrawRingLines(*center, *innerRadius, *outerRadius, *startAngle, *endAngle, *segments, *color);}    // Draw ring outline
DECLARE(void DrawRectangleRetPtr(int *posX,  int *posY,  int *width,  int *height,  Color *color)){DrawRectangle(*posX, *posY, *width, *height, *color);}                        // Draw a color-filled rectangle
DECLARE(void DrawRectangleVRetPtr(Vector2 *position,  Vector2 *size,  Color *color)){DrawRectangleV(*position, *size, *color);}                                  // Draw a color-filled rectangle (Vector version)
DECLARE(void DrawRectangleRecRetPtr(Rectangle *rec,  Color *color)){DrawRectangleRec(*rec, *color);}                                                 // Draw a color-filled rectangle
DECLARE(void DrawRectangleProRetPtr(Rectangle *rec,  Vector2 *origin,  float *rotation,  Color *color)){DrawRectanglePro(*rec, *origin, *rotation, *color);}                 // Draw a color-filled rectangle with pro parameters
DECLARE(void DrawRectangleGradientVRetPtr(int *posX,  int *posY,  int *width,  int *height,  Color *top,  Color *bottom)){DrawRectangleGradientV(*posX, *posY, *width, *height, *top, *bottom);}   // Draw a vertical-gradient-filled rectangle
DECLARE(void DrawRectangleGradientHRetPtr(int *posX,  int *posY,  int *width,  int *height,  Color *left,  Color *right)){DrawRectangleGradientH(*posX, *posY, *width, *height, *left, *right);}   // Draw a horizontal-gradient-filled rectangle
DECLARE(void DrawRectangleGradientExRetPtr(Rectangle *rec,  Color *topLeft,  Color *bottomLeft,  Color *topRight,  Color *bottomRight)){DrawRectangleGradientEx(*rec, *topLeft, *bottomLeft, *topRight, *bottomRight);} // Draw a gradient-filled rectangle with custom vertex colors
DECLARE(void DrawRectangleLinesRetPtr(int *posX,  int *posY,  int *width,  int *height,  Color *color)){DrawRectangleLines(*posX, *posY, *width, *height, *color);}                   // Draw rectangle outline
DECLARE(void DrawRectangleLinesExRetPtr(Rectangle *rec,  float *lineThick,  Color *color)){DrawRectangleLinesEx(*rec, *lineThick, *color);}                            // Draw rectangle outline with extended parameters
DECLARE(void DrawRectangleRoundedRetPtr(Rectangle *rec,  float *roundness,  int *segments,  Color *color)){DrawRectangleRounded(*rec, *roundness, *segments, *color);}              // Draw rectangle with rounded edges
DECLARE(void DrawRectangleRoundedLinesRetPtr(Rectangle *rec,  float *roundness,  int *segments,  Color *color)){DrawRectangleRoundedLines(*rec, *roundness, *segments, *color);}         // Draw rectangle lines with rounded edges
DECLARE(void DrawRectangleRoundedLinesExRetPtr(Rectangle *rec,  float *roundness,  int *segments,  float *lineThick,  Color *color)){DrawRectangleRoundedLinesEx(*rec, *roundness, *segments, *lineThick, *color);} // Draw rectangle with rounded edges outline
DECLARE(void DrawTriangleRetPtr(Vector2 *v1,  Vector2 *v2,  Vector2 *v3,  Color *color)){DrawTriangle(*v1, *v2, *v3, *color);}                                // Draw a color-filled triangle (vertex in counter-clockwise order!)
DECLARE(void DrawTriangleLinesRetPtr(Vector2 *v1,  Vector2 *v2,  Vector2 *v3,  Color *color)){DrawTriangleLines(*v1, *v2, *v3, *color);}                           // Draw triangle outline (vertex in counter-clockwise order!)
DECLARE(void DrawTriangleFanRetPtr(const Vector2 **points,  int *pointCount,  Color *color)){DrawTriangleFan(*points, *pointCount, *color);}                          // Draw a triangle fan defined by points (first vertex is the center)
DECLARE(void DrawTriangleStripRetPtr(const Vector2 **points,  int *pointCount,  Color *color)){DrawTriangleStrip(*points, *pointCount, *color);}                        // Draw a triangle strip defined by points
DECLARE(void DrawPolyRetPtr(Vector2 *center,  int *sides,  float *radius,  float *rotation,  Color *color)){DrawPoly(*center, *sides, *radius, *rotation, *color);}               // Draw a regular polygon (Vector version)
DECLARE(void DrawPolyLinesRetPtr(Vector2 *center,  int *sides,  float *radius,  float *rotation,  Color *color)){DrawPolyLines(*center, *sides, *radius, *rotation, *color);}          // Draw a polygon outline of n sides
DECLARE(void DrawPolyLinesExRetPtr(Vector2 *center,  int *sides,  float *radius,  float *rotation,  float *lineThick,  Color *color)){DrawPolyLinesEx(*center, *sides, *radius, *rotation, *lineThick, *color);} // Draw a polygon outline of n sides with extended parameters
DECLARE(void DrawSplineLinearRetPtr(const Vector2 **points,  int *pointCount,  float *thick,  Color *color)){DrawSplineLinear(*points, *pointCount, *thick, *color);}                  // Draw spline: Linear, minimum 2 points
DECLARE(void DrawSplineBasisRetPtr(const Vector2 **points,  int *pointCount,  float *thick,  Color *color)){DrawSplineBasis(*points, *pointCount, *thick, *color);}                   // Draw spline: B-Spline, minimum 4 points
DECLARE(void DrawSplineCatmullRomRetPtr(const Vector2 **points,  int *pointCount,  float *thick,  Color *color)){DrawSplineCatmullRom(*points, *pointCount, *thick, *color);}              // Draw spline: Catmull-Rom, minimum 4 points
DECLARE(void DrawSplineBezierQuadraticRetPtr(const Vector2 **points,  int *pointCount,  float *thick,  Color *color)){DrawSplineBezierQuadratic(*points, *pointCount, *thick, *color);}         // Draw spline: Quadratic Bezier, minimum 3 points (1 control point): [p1, c2, p3, c4...]
DECLARE(void DrawSplineBezierCubicRetPtr(const Vector2 **points,  int *pointCount,  float *thick,  Color *color)){DrawSplineBezierCubic(*points, *pointCount, *thick, *color);}             // Draw spline: Cubic Bezier, minimum 4 points (2 control points): [p1, c2, c3, p4, c5, c6...]
DECLARE(void DrawSplineSegmentLinearRetPtr(Vector2 *p1,  Vector2 *p2,  float *thick,  Color *color)){DrawSplineSegmentLinear(*p1, *p2, *thick, *color);}                    // Draw spline segment: Linear, 2 points
DECLARE(void DrawSplineSegmentBasisRetPtr(Vector2 *p1,  Vector2 *p2,  Vector2 *p3,  Vector2 *p4,  float *thick,  Color *color)){DrawSplineSegmentBasis(*p1, *p2, *p3, *p4, *thick, *color);} // Draw spline segment: B-Spline, 4 points
DECLARE(void DrawSplineSegmentCatmullRomRetPtr(Vector2 *p1,  Vector2 *p2,  Vector2 *p3,  Vector2 *p4,  float *thick,  Color *color)){DrawSplineSegmentCatmullRom(*p1, *p2, *p3, *p4, *thick, *color);} // Draw spline segment: Catmull-Rom, 4 points
DECLARE(void DrawSplineSegmentBezierQuadraticRetPtr(Vector2 *p1,  Vector2 *c2,  Vector2 *p3,  float *thick,  Color *color)){DrawSplineSegmentBezierQuadratic(*p1, *c2, *p3, *thick, *color);} // Draw spline segment: Quadratic Bezier, 2 points, 1 control point
DECLARE(void DrawSplineSegmentBezierCubicRetPtr(Vector2 *p1,  Vector2 *c2,  Vector2 *c3,  Vector2 *p4,  float *thick,  Color *color)){DrawSplineSegmentBezierCubic(*p1, *c2, *c3, *p4, *thick, *color);} // Draw spline segment: Cubic Bezier, 2 points, 2 control points
DECLARE(void GetSplinePointLinearRetPtr(Vector2 *ret, Vector2 *startPos,  Vector2 *endPos,  float *t)){*ret=GetSplinePointLinear(*startPos, *endPos, *t);}                           // Get (evaluate) spline point: Linear
DECLARE(void GetSplinePointBasisRetPtr(Vector2 *ret, Vector2 *p1,  Vector2 *p2,  Vector2 *p3,  Vector2 *p4,  float *t)){*ret=GetSplinePointBasis(*p1, *p2, *p3, *p4, *t);}              // Get (evaluate) spline point: B-Spline
DECLARE(void GetSplinePointCatmullRomRetPtr(Vector2 *ret, Vector2 *p1,  Vector2 *p2,  Vector2 *p3,  Vector2 *p4,  float *t)){*ret=GetSplinePointCatmullRom(*p1, *p2, *p3, *p4, *t);}         // Get (evaluate) spline point: Catmull-Rom
DECLARE(void GetSplinePointBezierQuadRetPtr(Vector2 *ret, Vector2 *p1,  Vector2 *c2,  Vector2 *p3,  float *t)){*ret=GetSplinePointBezierQuad(*p1, *c2, *p3, *t);}                     // Get (evaluate) spline point: Quadratic Bezier
DECLARE(void GetSplinePointBezierCubicRetPtr(Vector2 *ret, Vector2 *p1,  Vector2 *c2,  Vector2 *c3,  Vector2 *p4,  float *t)){*ret=GetSplinePointBezierCubic(*p1, *c2, *c3, *p4, *t);}        // Get (evaluate) spline point: Cubic Bezier
DECLARE(void CheckCollisionRecsRetPtr(bool *ret, Rectangle *rec1,  Rectangle *rec2)){*ret=CheckCollisionRecs(*rec1, *rec2);}                                           // Check collision between two rectangles
DECLARE(void CheckCollisionCirclesRetPtr(bool *ret, Vector2 *center1,  float *radius1,  Vector2 *center2,  float *radius2)){*ret=CheckCollisionCircles(*center1, *radius1, *center2, *radius2);}        // Check collision between two circles
DECLARE(void CheckCollisionCircleRecRetPtr(bool *ret, Vector2 *center,  float *radius,  Rectangle *rec)){*ret=CheckCollisionCircleRec(*center, *radius, *rec);}                         // Check collision between circle and rectangle
DECLARE(void CheckCollisionCircleLineRetPtr(bool *ret, Vector2 *center,  float *radius,  Vector2 *p1,  Vector2 *p2)){*ret=CheckCollisionCircleLine(*center, *radius, *p1, *p2);}               // Check if circle collides with a line created betweeen two points [p1] and [p2]
DECLARE(void CheckCollisionPointRecRetPtr(bool *ret, Vector2 *point,  Rectangle *rec)){*ret=CheckCollisionPointRec(*point, *rec);}                                         // Check if point is inside rectangle
DECLARE(void CheckCollisionPointCircleRetPtr(bool *ret, Vector2 *point,  Vector2 *center,  float *radius)){*ret=CheckCollisionPointCircle(*point, *center, *radius);}                       // Check if point is inside circle
DECLARE(void CheckCollisionPointTriangleRetPtr(bool *ret, Vector2 *point,  Vector2 *p1,  Vector2 *p2,  Vector2 *p3)){*ret=CheckCollisionPointTriangle(*point, *p1, *p2, *p3);}               // Check if point is inside a triangle
DECLARE(void CheckCollisionPointLineRetPtr(bool *ret, Vector2 *point,  Vector2 *p1,  Vector2 *p2,  int *threshold)){*ret=CheckCollisionPointLine(*point, *p1, *p2, *threshold);}                // Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
DECLARE(void CheckCollisionPointPolyRetPtr(bool *ret, Vector2 *point,  const Vector2 **points,  int *pointCount)){*ret=CheckCollisionPointPoly(*point, *points, *pointCount);}                // Check if point is within a polygon described by array of vertices
DECLARE(void CheckCollisionLinesRetPtr(bool *ret, Vector2 *startPos1,  Vector2 *endPos1,  Vector2 *startPos2,  Vector2 *endPos2,  Vector2 **collisionPoint)){*ret=CheckCollisionLines(*startPos1, *endPos1, *startPos2, *endPos2, *collisionPoint);} // Check the collision between two lines defined by two points each, returns collision point by reference
DECLARE(void GetCollisionRecRetPtr(Rectangle *ret, Rectangle *rec1,  Rectangle *rec2)){*ret=GetCollisionRec(*rec1, *rec2);}                                         // Get collision rectangle for two rectangles collision
DECLARE(void LoadImageRetPtr(Image *ret, const char **fileName)){*ret=LoadImage(*fileName);}                                                             // Load image from file into CPU memory (RAM)
DECLARE(void LoadImageRawRetPtr(Image *ret, const char **fileName,  int *width,  int *height,  int *format,  int *headerSize)){*ret=LoadImageRaw(*fileName, *width, *height, *format, *headerSize);}       // Load image from RAW file data
DECLARE(void LoadImageAnimRetPtr(Image *ret, const char **fileName,  int **frames)){*ret=LoadImageAnim(*fileName, *frames);}                                            // Load image sequence from file (frames appended to image.data)
DECLARE(void LoadImageAnimFromMemoryRetPtr(Image *ret, const char **fileType,  const unsigned char **fileData,  int *dataSize,  int **frames)){*ret=LoadImageAnimFromMemory(*fileType, *fileData, *dataSize, *frames);} // Load image sequence from memory buffer
DECLARE(void LoadImageFromMemoryRetPtr(Image *ret, const char **fileType,  const unsigned char **fileData,  int *dataSize)){*ret=LoadImageFromMemory(*fileType, *fileData, *dataSize);}      // Load image from memory buffer, fileType refers to extension: i.e. '.png'
DECLARE(void LoadImageFromTextureRetPtr(Image *ret, Texture2D *texture)){*ret=LoadImageFromTexture(*texture);}                                                     // Load image from GPU texture data
DECLARE(void LoadImageFromScreenRetPtr(Image *ret)){*ret=LoadImageFromScreen();}                                                                   // Load image from screen buffer and (screenshot)
DECLARE(void IsImageValidRetPtr(bool *ret, Image *image)){*ret=IsImageValid(*image);}                                                                    // Check if an image is valid (data and parameters)
DECLARE(void UnloadImageRetPtr(Image *image)){UnloadImage(*image);}                                                                     // Unload image from CPU memory (RAM)
DECLARE(void ExportImageRetPtr(bool *ret, Image *image,  const char **fileName)){*ret=ExportImage(*image, *fileName);}                                               // Export image data to file, returns true on success
DECLARE(void ExportImageToMemoryRetPtr(unsigned char **ret, Image *image,  const char **fileType,  int **fileSize)){*ret=ExportImageToMemory(*image, *fileType, *fileSize);}              // Export image to memory buffer
DECLARE(void ExportImageAsCodeRetPtr(bool *ret, Image *image,  const char **fileName)){*ret=ExportImageAsCode(*image, *fileName);}                                         // Export image as code file defining an array of bytes, returns true on success
DECLARE(void GenImageColorRetPtr(Image *ret, int *width,  int *height,  Color *color)){*ret=GenImageColor(*width, *height, *color);}                                           // Generate image: plain color
DECLARE(void GenImageGradientLinearRetPtr(Image *ret, int *width,  int *height,  int *direction,  Color *start,  Color *end)){*ret=GenImageGradientLinear(*width, *height, *direction, *start, *end);}        // Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
DECLARE(void GenImageGradientRadialRetPtr(Image *ret, int *width,  int *height,  float *density,  Color *inner,  Color *outer)){*ret=GenImageGradientRadial(*width, *height, *density, *inner, *outer);}      // Generate image: radial gradient
DECLARE(void GenImageGradientSquareRetPtr(Image *ret, int *width,  int *height,  float *density,  Color *inner,  Color *outer)){*ret=GenImageGradientSquare(*width, *height, *density, *inner, *outer);}      // Generate image: square gradient
DECLARE(void GenImageCheckedRetPtr(Image *ret, int *width,  int *height,  int *checksX,  int *checksY,  Color *col1,  Color *col2)){*ret=GenImageChecked(*width, *height, *checksX, *checksY, *col1, *col2);}    // Generate image: checked
DECLARE(void GenImageWhiteNoiseRetPtr(Image *ret, int *width,  int *height,  float *factor)){*ret=GenImageWhiteNoise(*width, *height, *factor);}                                     // Generate image: white noise
DECLARE(void GenImagePerlinNoiseRetPtr(Image *ret, int *width,  int *height,  int *offsetX,  int *offsetY,  float *scale)){*ret=GenImagePerlinNoise(*width, *height, *offsetX, *offsetY, *scale);}           // Generate image: perlin noise
DECLARE(void GenImageCellularRetPtr(Image *ret, int *width,  int *height,  int *tileSize)){*ret=GenImageCellular(*width, *height, *tileSize);}                                       // Generate image: cellular algorithm, bigger tileSize means bigger cells
DECLARE(void GenImageTextRetPtr(Image *ret, int *width,  int *height,  const char **text)){*ret=GenImageText(*width, *height, *text);}                                       // Generate image: grayscale image from text data
DECLARE(void ImageCopyRetPtr(Image *ret, Image *image)){*ret=ImageCopy(*image);}                                                                      // Create an image duplicate (useful for transformations)
DECLARE(void ImageFromImageRetPtr(Image *ret, Image *image,  Rectangle *rec)){*ret=ImageFromImage(*image, *rec);}                                                  // Create an image from another image piece
DECLARE(void ImageFromChannelRetPtr(Image *ret, Image *image,  int *selectedChannel)){*ret=ImageFromChannel(*image, *selectedChannel);}                                          // Create an image from a selected channel of another image (GRAYSCALE)
DECLARE(void ImageTextRetPtr(Image *ret, const char **text,  int *fontSize,  Color *color)){*ret=ImageText(*text, *fontSize, *color);}                                      // Create an image from text (default font)
DECLARE(void ImageTextExRetPtr(Image *ret, Font *font,  const char **text,  float *fontSize,  float *spacing,  Color *tint)){*ret=ImageTextEx(*font, *text, *fontSize, *spacing, *tint);}         // Create an image from text (custom sprite font)
DECLARE(void ImageFormatRetPtr(Image **image,  int *newFormat)){ImageFormat(*image, *newFormat);}                                                     // Convert image data to desired format
DECLARE(void ImageToPOTRetPtr(Image **image,  Color *fill)){ImageToPOT(*image, *fill);}                                                         // Convert image to POT (power-of-two)
DECLARE(void ImageCropRetPtr(Image **image,  Rectangle *crop)){ImageCrop(*image, *crop);}                                                      // Crop an image to a defined rectangle
DECLARE(void ImageAlphaCropRetPtr(Image **image,  float *threshold)){ImageAlphaCrop(*image, *threshold);}                                                // Crop image depending on alpha value
DECLARE(void ImageAlphaClearRetPtr(Image **image,  Color *color,  float *threshold)){ImageAlphaClear(*image, *color, *threshold);}                                  // Clear alpha channel to desired color
DECLARE(void ImageAlphaMaskRetPtr(Image **image,  Image *alphaMask)){ImageAlphaMask(*image, *alphaMask);}                                                // Apply alpha mask to image
DECLARE(void ImageAlphaPremultiplyRetPtr(Image **image)){ImageAlphaPremultiply(*image);}                                                          // Premultiply alpha channel
DECLARE(void ImageBlurGaussianRetPtr(Image **image,  int *blurSize)){ImageBlurGaussian(*image, *blurSize);}                                                // Apply Gaussian blur using a box blur approximation
DECLARE(void ImageKernelConvolutionRetPtr(Image **image,  const float **kernel,  int *kernelSize)){ImageKernelConvolution(*image, *kernel, *kernelSize);}                    // Apply custom square convolution kernel to image
DECLARE(void ImageResizeRetPtr(Image **image,  int *newWidth,  int *newHeight)){ImageResize(*image, *newWidth, *newHeight);}                                       // Resize image (Bicubic scaling algorithm)
DECLARE(void ImageResizeNNRetPtr(Image **image,  int *newWidth,  int *newHeight)){ImageResizeNN(*image, *newWidth, *newHeight);}                                      // Resize image (Nearest-Neighbor scaling algorithm)
DECLARE(void ImageResizeCanvasRetPtr(Image **image,  int *newWidth,  int *newHeight,  int *offsetX,  int *offsetY,  Color *fill)){ImageResizeCanvas(*image, *newWidth, *newHeight, *offsetX, *offsetY, *fill);} // Resize canvas and fill with color
DECLARE(void ImageMipmapsRetPtr(Image **image)){ImageMipmaps(*image);}                                                                   // Compute all mipmap levels for a provided image
DECLARE(void ImageDitherRetPtr(Image **image,  int *rBpp,  int *gBpp,  int *bBpp,  int *aBpp)){ImageDither(*image, *rBpp, *gBpp, *bBpp, *aBpp);}                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
DECLARE(void ImageFlipVerticalRetPtr(Image **image)){ImageFlipVertical(*image);}                                                              // Flip image vertically
DECLARE(void ImageFlipHorizontalRetPtr(Image **image)){ImageFlipHorizontal(*image);}                                                            // Flip image horizontally
DECLARE(void ImageRotateRetPtr(Image **image,  int *degrees)){ImageRotate(*image, *degrees);}                                                       // Rotate image by input angle in degrees (-359 to 359)
DECLARE(void ImageRotateCWRetPtr(Image **image)){ImageRotateCW(*image);}                                                                  // Rotate image clockwise 90deg
DECLARE(void ImageRotateCCWRetPtr(Image **image)){ImageRotateCCW(*image);}                                                                 // Rotate image counter-clockwise 90deg
DECLARE(void ImageColorTintRetPtr(Image **image,  Color *color)){ImageColorTint(*image, *color);}                                                    // Modify image color: tint
DECLARE(void ImageColorInvertRetPtr(Image **image)){ImageColorInvert(*image);}                                                               // Modify image color: invert
DECLARE(void ImageColorGrayscaleRetPtr(Image **image)){ImageColorGrayscale(*image);}                                                            // Modify image color: grayscale
DECLARE(void ImageColorContrastRetPtr(Image **image,  float *contrast)){ImageColorContrast(*image, *contrast);}                                             // Modify image color: contrast (-100 to 100)
DECLARE(void ImageColorBrightnessRetPtr(Image **image,  int *brightness)){ImageColorBrightness(*image, *brightness);}                                           // Modify image color: brightness (-255 to 255)
DECLARE(void ImageColorReplaceRetPtr(Image **image,  Color *color,  Color *replace)){ImageColorReplace(*image, *color, *replace);}                                  // Modify image color: replace color
DECLARE(void LoadImageColorsRetPtr(Color **ret, Image *image)){*ret=LoadImageColors(*image);}                                                               // Load color data from image as a Color array (RGBA - 32bit)
DECLARE(void LoadImagePaletteRetPtr(Color **ret, Image *image,  int *maxPaletteSize,  int **colorCount)){*ret=LoadImagePalette(*image, *maxPaletteSize, *colorCount);}                         // Load colors palette from image as a Color array (RGBA - 32bit)
DECLARE(void UnloadImageColorsRetPtr(Color **colors)){UnloadImageColors(*colors);}                                                             // Unload color data loaded with LoadImageColors()
DECLARE(void UnloadImagePaletteRetPtr(Color **colors)){UnloadImagePalette(*colors);}                                                            // Unload colors palette loaded with LoadImagePalette()
DECLARE(void GetImageAlphaBorderRetPtr(Rectangle *ret, Image *image,  float *threshold)){*ret=GetImageAlphaBorder(*image, *threshold);}                                       // Get image alpha border rectangle
DECLARE(void GetImageColorRetPtr(Color *ret, Image *image,  int *x,  int *y)){*ret=GetImageColor(*image, *x, *y);}                                                    // Get image pixel color at (x, y) position
DECLARE(void ImageClearBackgroundRetPtr(Image **dst,  Color *color)){ImageClearBackground(*dst, *color);}                                                // Clear image background with given color
DECLARE(void ImageDrawPixelRetPtr(Image **dst,  int *posX,  int *posY,  Color *color)){ImageDrawPixel(*dst, *posX, *posY, *color);}                                  // Draw pixel within an image
DECLARE(void ImageDrawPixelVRetPtr(Image **dst,  Vector2 *position,  Color *color)){ImageDrawPixelV(*dst, *position, *color);}                                   // Draw pixel within an image (Vector version)
DECLARE(void ImageDrawLineRetPtr(Image **dst,  int *startPosX,  int *startPosY,  int *endPosX,  int *endPosY,  Color *color)){ImageDrawLine(*dst, *startPosX, *startPosY, *endPosX, *endPosY, *color);} // Draw line within an image
DECLARE(void ImageDrawLineVRetPtr(Image **dst,  Vector2 *start,  Vector2 *end,  Color *color)){ImageDrawLineV(*dst, *start, *end, *color);}                          // Draw line within an image (Vector version)
DECLARE(void ImageDrawLineExRetPtr(Image **dst,  Vector2 *start,  Vector2 *end,  int *thick,  Color *color)){ImageDrawLineEx(*dst, *start, *end, *thick, *color);}              // Draw a line defining thickness within an image
DECLARE(void ImageDrawCircleRetPtr(Image **dst,  int *centerX,  int *centerY,  int *radius,  Color *color)){ImageDrawCircle(*dst, *centerX, *centerY, *radius, *color);}               // Draw a filled circle within an image
DECLARE(void ImageDrawCircleVRetPtr(Image **dst,  Vector2 *center,  int *radius,  Color *color)){ImageDrawCircleV(*dst, *center, *radius, *color);}                        // Draw a filled circle within an image (Vector version)
DECLARE(void ImageDrawCircleLinesRetPtr(Image **dst,  int *centerX,  int *centerY,  int *radius,  Color *color)){ImageDrawCircleLines(*dst, *centerX, *centerY, *radius, *color);}          // Draw circle outline within an image
DECLARE(void ImageDrawCircleLinesVRetPtr(Image **dst,  Vector2 *center,  int *radius,  Color *color)){ImageDrawCircleLinesV(*dst, *center, *radius, *color);}                   // Draw circle outline within an image (Vector version)
DECLARE(void ImageDrawRectangleRetPtr(Image **dst,  int *posX,  int *posY,  int *width,  int *height,  Color *color)){ImageDrawRectangle(*dst, *posX, *posY, *width, *height, *color);}       // Draw rectangle within an image
DECLARE(void ImageDrawRectangleVRetPtr(Image **dst,  Vector2 *position,  Vector2 *size,  Color *color)){ImageDrawRectangleV(*dst, *position, *size, *color);}                 // Draw rectangle within an image (Vector version)
DECLARE(void ImageDrawRectangleRecRetPtr(Image **dst,  Rectangle *rec,  Color *color)){ImageDrawRectangleRec(*dst, *rec, *color);}                                // Draw rectangle within an image
DECLARE(void ImageDrawRectangleLinesRetPtr(Image **dst,  Rectangle *rec,  int *thick,  Color *color)){ImageDrawRectangleLines(*dst, *rec, *thick, *color);}                   // Draw rectangle lines within an image
DECLARE(void ImageDrawTriangleRetPtr(Image **dst,  Vector2 *v1,  Vector2 *v2,  Vector2 *v3,  Color *color)){ImageDrawTriangle(*dst, *v1, *v2, *v3, *color);}               // Draw triangle within an image
DECLARE(void ImageDrawTriangleExRetPtr(Image **dst,  Vector2 *v1,  Vector2 *v2,  Vector2 *v3,  Color *c1,  Color *c2,  Color *c3)){ImageDrawTriangleEx(*dst, *v1, *v2, *v3, *c1, *c2, *c3);} // Draw triangle with interpolated colors within an image
DECLARE(void ImageDrawTriangleLinesRetPtr(Image **dst,  Vector2 *v1,  Vector2 *v2,  Vector2 *v3,  Color *color)){ImageDrawTriangleLines(*dst, *v1, *v2, *v3, *color);}          // Draw triangle outline within an image
DECLARE(void ImageDrawTriangleFanRetPtr(Image **dst,  Vector2 **points,  int *pointCount,  Color *color)){ImageDrawTriangleFan(*dst, *points, *pointCount, *color);}               // Draw a triangle fan defined by points within an image (first vertex is the center)
DECLARE(void ImageDrawTriangleStripRetPtr(Image **dst,  Vector2 **points,  int *pointCount,  Color *color)){ImageDrawTriangleStrip(*dst, *points, *pointCount, *color);}             // Draw a triangle strip defined by points within an image
DECLARE(void ImageDrawRetPtr(Image **dst,  Image *src,  Rectangle *srcRec,  Rectangle *dstRec,  Color *tint)){ImageDraw(*dst, *src, *srcRec, *dstRec, *tint);}             // Draw a source image within a destination image (tint applied to source)
DECLARE(void ImageDrawTextRetPtr(Image **dst,  const char **text,  int *posX,  int *posY,  int *fontSize,  Color *color)){ImageDrawText(*dst, *text, *posX, *posY, *fontSize, *color);}   // Draw text (using default font) within an image (destination)
DECLARE(void ImageDrawTextExRetPtr(Image **dst,  Font *font,  const char **text,  Vector2 *position,  float *fontSize,  float *spacing,  Color *tint)){ImageDrawTextEx(*dst, *font, *text, *position, *fontSize, *spacing, *tint);} // Draw text (custom sprite font) within an image (destination)
DECLARE(void LoadTextureRetPtr(Texture2D *ret, const char **fileName)){*ret=LoadTexture(*fileName);}                                                       // Load texture from file into GPU memory (VRAM)
DECLARE(void LoadTextureFromImageRetPtr(Texture2D *ret, Image *image)){*ret=LoadTextureFromImage(*image);}                                                       // Load texture from image data
DECLARE(void LoadTextureCubemapRetPtr(TextureCubemap *ret, Image *image,  int *layout)){*ret=LoadTextureCubemap(*image, *layout);}                                        // Load cubemap from image, multiple image cubemap layouts supported
DECLARE(void LoadRenderTextureRetPtr(RenderTexture2D *ret, int *width,  int *height)){*ret=LoadRenderTexture(*width, *height);}                                          // Load texture for rendering (framebuffer)
DECLARE(void IsTextureValidRetPtr(bool *ret, Texture2D *texture)){*ret=IsTextureValid(*texture);}                                                            // Check if a texture is valid (loaded in GPU)
DECLARE(void UnloadTextureRetPtr(Texture2D *texture)){UnloadTexture(*texture);}                                                             // Unload texture from GPU memory (VRAM)
DECLARE(void IsRenderTextureValidRetPtr(bool *ret, RenderTexture2D *target)){*ret=IsRenderTextureValid(*target);}                                                 // Check if a render texture is valid (loaded in GPU)
DECLARE(void UnloadRenderTextureRetPtr(RenderTexture2D *target)){UnloadRenderTexture(*target);}                                                  // Unload render texture from GPU memory (VRAM)
DECLARE(void UpdateTextureRetPtr(Texture2D *texture,  const void **pixels)){UpdateTexture(*texture, *pixels);}                                         // Update GPU texture with new data
DECLARE(void UpdateTextureRecRetPtr(Texture2D *texture,  Rectangle *rec,  const void **pixels)){UpdateTextureRec(*texture, *rec, *pixels);}                       // Update GPU texture rectangle with new data
DECLARE(void GenTextureMipmapsRetPtr(Texture2D **texture)){GenTextureMipmaps(*texture);}                                                        // Generate GPU mipmaps for a texture
DECLARE(void SetTextureFilterRetPtr(Texture2D *texture,  int *filter)){SetTextureFilter(*texture, *filter);}                                              // Set texture scaling filter mode
DECLARE(void SetTextureWrapRetPtr(Texture2D *texture,  int *wrap)){SetTextureWrap(*texture, *wrap);}                                                  // Set texture wrapping mode
DECLARE(void DrawTextureRetPtr(Texture2D *texture,  int *posX,  int *posY,  Color *tint)){DrawTexture(*texture, *posX, *posY, *tint);}                               // Draw a Texture2D
DECLARE(void DrawTextureVRetPtr(Texture2D *texture,  Vector2 *position,  Color *tint)){DrawTextureV(*texture, *position, *tint);}                                // Draw a Texture2D with position defined as Vector2
DECLARE(void DrawTextureExRetPtr(Texture2D *texture,  Vector2 *position,  float *rotation,  float *scale,  Color *tint)){DrawTextureEx(*texture, *position, *rotation, *scale, *tint);}  // Draw a Texture2D with extended parameters
DECLARE(void DrawTextureRecRetPtr(Texture2D *texture,  Rectangle *source,  Vector2 *position,  Color *tint)){DrawTextureRec(*texture, *source, *position, *tint);}            // Draw a part of a texture defined by a rectangle
DECLARE(void DrawTextureProRetPtr(Texture2D *texture,  Rectangle *source,  Rectangle *dest,  Vector2 *origin,  float *rotation,  Color *tint)){DrawTexturePro(*texture, *source, *dest, *origin, *rotation, *tint);} // Draw a part of a texture defined by a rectangle with 'pro' parameters
DECLARE(void DrawTextureNPatchRetPtr(Texture2D *texture,  NPatchInfo *nPatchInfo,  Rectangle *dest,  Vector2 *origin,  float *rotation,  Color *tint)){DrawTextureNPatch(*texture, *nPatchInfo, *dest, *origin, *rotation, *tint);} // Draws a texture (or part of it) that stretches or shrinks nicely
DECLARE(void ColorIsEqualRetPtr(bool *ret, Color *col1,  Color *col2)){*ret=ColorIsEqual(*col1, *col2);}                            // Check if two colors are equal
DECLARE(void FadeRetPtr(Color *ret, Color *color,  float *alpha)){*ret=Fade(*color, *alpha);}                                 // Get color with alpha applied, alpha goes from 0.0f to 1.0f
DECLARE(void ColorToIntRetPtr(int *ret, Color *color)){*ret=ColorToInt(*color);}                                          // Get hexadecimal value for a Color (0xRRGGBBAA)
DECLARE(void ColorNormalizeRetPtr(Vector4 *ret, Color *color)){*ret=ColorNormalize(*color);}                                  // Get Color normalized as float [0..1]
DECLARE(void ColorFromNormalizedRetPtr(Color *ret, Vector4 *normalized)){*ret=ColorFromNormalized(*normalized);}                        // Get Color from normalized values [0..1]
DECLARE(void ColorToHSVRetPtr(Vector3 *ret, Color *color)){*ret=ColorToHSV(*color);}                                      // Get HSV values for a Color, hue [0..360], saturation/value [0..1]
DECLARE(void ColorFromHSVRetPtr(Color *ret, float *hue,  float *saturation,  float *value)){*ret=ColorFromHSV(*hue, *saturation, *value);}         // Get a Color from HSV values, hue [0..360], saturation/value [0..1]
DECLARE(void ColorTintRetPtr(Color *ret, Color *color,  Color *tint)){*ret=ColorTint(*color, *tint);}                             // Get color multiplied with another color
DECLARE(void ColorBrightnessRetPtr(Color *ret, Color *color,  float *factor)){*ret=ColorBrightness(*color, *factor);}                     // Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
DECLARE(void ColorContrastRetPtr(Color *ret, Color *color,  float *contrast)){*ret=ColorContrast(*color, *contrast);}                     // Get color with contrast correction, contrast values between -1.0f and 1.0f
DECLARE(void ColorAlphaRetPtr(Color *ret, Color *color,  float *alpha)){*ret=ColorAlpha(*color, *alpha);}                           // Get color with alpha applied, alpha goes from 0.0f to 1.0f
DECLARE(void ColorAlphaBlendRetPtr(Color *ret, Color *dst,  Color *src,  Color *tint)){*ret=ColorAlphaBlend(*dst, *src, *tint);}              // Get src alpha-blended into dst color with tint
DECLARE(void ColorLerpRetPtr(Color *ret, Color *color1,  Color *color2,  float *factor)){*ret=ColorLerp(*color1, *color2, *factor);}            // Get color lerp interpolation between two colors, factor [0.0f..1.0f]
DECLARE(void GetColorRetPtr(Color *ret, unsigned int *hexValue)){*ret=GetColor(*hexValue);}                                // Get Color structure from hexadecimal value
DECLARE(void GetPixelColorRetPtr(Color *ret, void **srcPtr,  int *format)){*ret=GetPixelColor(*srcPtr, *format);}                        // Get Color from a source pixel pointer of certain format
DECLARE(void SetPixelColorRetPtr(void **dstPtr,  Color *color,  int *format)){SetPixelColor(*dstPtr, *color, *format);}            // Set color formatted into destination pixel pointer
DECLARE(void GetPixelDataSizeRetPtr(int *ret, int *width,  int *height,  int *format)){*ret=GetPixelDataSize(*width, *height, *format);}              // Get pixel data size in bytes for certain format
DECLARE(void GetFontDefaultRetPtr(Font *ret)){*ret=GetFontDefault();}                                                            // Get the default Font
DECLARE(void LoadFontRetPtr(Font *ret, const char **fileName)){*ret=LoadFont(*fileName);}                                                  // Load font from file into GPU memory (VRAM)
DECLARE(void LoadFontExRetPtr(Font *ret, const char **fileName,  int *fontSize,  int **codepoints,  int *codepointCount)){*ret=LoadFontEx(*fileName, *fontSize, *codepoints, *codepointCount);} // Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character set, font size is provided in pixels height
DECLARE(void LoadFontFromImageRetPtr(Font *ret, Image *image,  Color *key,  int *firstChar)){*ret=LoadFontFromImage(*image, *key, *firstChar);}                        // Load font from Image (XNA style)
DECLARE(void LoadFontFromMemoryRetPtr(Font *ret, const char **fileType,  const unsigned char **fileData,  int *dataSize,  int *fontSize,  int **codepoints,  int *codepointCount)){*ret=LoadFontFromMemory(*fileType, *fileData, *dataSize, *fontSize, *codepoints, *codepointCount);} // Load font from memory buffer, fileType refers to extension: i.e. '.ttf'
DECLARE(void IsFontValidRetPtr(bool *ret, Font *font)){*ret=IsFontValid(*font);}                                                          // Check if a font is valid (font data loaded, WARNING: GPU texture not checked)
DECLARE(void LoadFontDataRetPtr(GlyphInfo **ret, const unsigned char **fileData,  int *dataSize,  int *fontSize,  int **codepoints,  int *codepointCount,  int *type)){*ret=LoadFontData(*fileData, *dataSize, *fontSize, *codepoints, *codepointCount, *type);} // Load font data for further use
DECLARE(void GenImageFontAtlasRetPtr(Image *ret, const GlyphInfo **glyphs,  Rectangle ***glyphRecs,  int *glyphCount,  int *fontSize,  int *padding,  int *packMethod)){*ret=GenImageFontAtlas(*glyphs, *glyphRecs, *glyphCount, *fontSize, *padding, *packMethod);} // Generate image font atlas using chars info
DECLARE(void UnloadFontDataRetPtr(GlyphInfo **glyphs,  int *glyphCount)){UnloadFontData(*glyphs, *glyphCount);}                               // Unload font chars info data (RAM)
DECLARE(void UnloadFontRetPtr(Font *font)){UnloadFont(*font);}                                                           // Unload font from GPU memory (VRAM)
DECLARE(void ExportFontAsCodeRetPtr(bool *ret, Font *font,  const char **fileName)){*ret=ExportFontAsCode(*font, *fileName);}                               // Export font as code file, returns true on success
DECLARE(void DrawFPSRetPtr(int *posX,  int *posY)){DrawFPS(*posX, *posY);}                                                     // Draw current FPS
DECLARE(void DrawTextRetPtr(const char **text,  int *posX,  int *posY,  int *fontSize,  Color *color)){DrawText(*text, *posX, *posY, *fontSize, *color);}       // Draw text (using default font)
DECLARE(void DrawTextExRetPtr(Font *font,  const char **text,  Vector2 *position,  float *fontSize,  float *spacing,  Color *tint)){DrawTextEx(*font, *text, *position, *fontSize, *spacing, *tint);} // Draw text using font and additional parameters
DECLARE(void DrawTextProRetPtr(Font *font,  const char **text,  Vector2 *position,  Vector2 *origin,  float *rotation,  float *fontSize,  float *spacing,  Color *tint)){DrawTextPro(*font, *text, *position, *origin, *rotation, *fontSize, *spacing, *tint);} // Draw text using Font and pro parameters (rotation)
DECLARE(void DrawTextCodepointRetPtr(Font *font,  int *codepoint,  Vector2 *position,  float *fontSize,  Color *tint)){DrawTextCodepoint(*font, *codepoint, *position, *fontSize, *tint);} // Draw one character (codepoint)
DECLARE(void DrawTextCodepointsRetPtr(Font *font,  const int **codepoints,  int *codepointCount,  Vector2 *position,  float *fontSize,  float *spacing,  Color *tint)){DrawTextCodepoints(*font, *codepoints, *codepointCount, *position, *fontSize, *spacing, *tint);} // Draw multiple character (codepoint)
DECLARE(void SetTextLineSpacingRetPtr(int *spacing)){SetTextLineSpacing(*spacing);}                                                 // Set vertical line spacing when drawing with line-breaks
DECLARE(void MeasureTextRetPtr(int *ret, const char **text,  int *fontSize)){*ret=MeasureText(*text, *fontSize);}                                      // Measure string width for default font
DECLARE(void MeasureTextExRetPtr(Vector2 *ret, Font *font,  const char **text,  float *fontSize,  float *spacing)){*ret=MeasureTextEx(*font, *text, *fontSize, *spacing);}    // Measure string size for Font
DECLARE(void GetGlyphIndexRetPtr(int *ret, Font *font,  int *codepoint)){*ret=GetGlyphIndex(*font, *codepoint);}                                          // Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found
DECLARE(void GetGlyphInfoRetPtr(GlyphInfo *ret, Font *font,  int *codepoint)){*ret=GetGlyphInfo(*font, *codepoint);}                                     // Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found
DECLARE(void GetGlyphAtlasRecRetPtr(Rectangle *ret, Font *font,  int *codepoint)){*ret=GetGlyphAtlasRec(*font, *codepoint);}                                 // Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found
DECLARE(void LoadUTF8RetPtr(char **ret, const int **codepoints,  int *length)){*ret=LoadUTF8(*codepoints, *length);}                // Load UTF-8 text encoded from codepoints array
DECLARE(void UnloadUTF8RetPtr(char **text)){UnloadUTF8(*text);}                                      // Unload UTF-8 text encoded from codepoints array
DECLARE(void LoadCodepointsRetPtr(int **ret, const char **text,  int **count)){*ret=LoadCodepoints(*text, *count);}                // Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
DECLARE(void UnloadCodepointsRetPtr(int **codepoints)){UnloadCodepoints(*codepoints);}                           // Unload codepoints data from memory
DECLARE(void GetCodepointCountRetPtr(int *ret, const char **text)){*ret=GetCodepointCount(*text);}                          // Get total number of codepoints in a UTF-8 encoded string
DECLARE(void GetCodepointRetPtr(int *ret, const char **text,  int **codepointSize)){*ret=GetCodepoint(*text, *codepointSize);}           // Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
DECLARE(void GetCodepointNextRetPtr(int *ret, const char **text,  int **codepointSize)){*ret=GetCodepointNext(*text, *codepointSize);}       // Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
DECLARE(void GetCodepointPreviousRetPtr(int *ret, const char **text,  int **codepointSize)){*ret=GetCodepointPrevious(*text, *codepointSize);}   // Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
DECLARE(void CodepointToUTF8RetPtr(const char **ret, int *codepoint,  int **utf8Size)){*ret=CodepointToUTF8(*codepoint, *utf8Size);}        // Encode one codepoint into UTF-8 byte array (array length returned as parameter)
DECLARE(void TextCopyRetPtr(int *ret, char **dst,  const char **src)){*ret=TextCopy(*dst, *src);}                                             // Copy one string to another, returns bytes copied
DECLARE(void TextIsEqualRetPtr(bool *ret, const char **text1,  const char **text2)){*ret=TextIsEqual(*text1, *text2);}                               // Check if two text string are equal
DECLARE(void TextLengthRetPtr(unsigned int *ret, const char **text)){*ret=TextLength(*text);}                                            // Get text length, checks for '\0' ending
DECLARE(void TextFormatRetPtr(const char **ret, const char **text,  void **args)){*ret=TextFormat(*text, *args);}                                        // Text formatting with variables (sprintf() style)
DECLARE(void TextSubtextRetPtr(const char **ret, const char **text,  int *position,  int *length)){*ret=TextSubtext(*text, *position, *length);}                  // Get a piece of a text string
DECLARE(void TextReplaceRetPtr(char **ret, const char **text,  const char **replace,  const char **by)){*ret=TextReplace(*text, *replace, *by);}             // Replace text string (WARNING: memory must be freed!)
DECLARE(void TextInsertRetPtr(char **ret, const char **text,  const char **insert,  int *position)){*ret=TextInsert(*text, *insert, *position);}                 // Insert text in a position (WARNING: memory must be freed!)
DECLARE(void TextJoinRetPtr(const char **ret, const char ***textList,  int *count,  const char **delimiter)){*ret=TextJoin(*textList, *count, *delimiter);}        // Join text strings with delimiter
DECLARE(void TextSplitRetPtr(const char ***ret, const char **text,  char *delimiter,  int **count)){*ret=TextSplit(*text, *delimiter, *count);}                 // Split text into multiple strings
DECLARE(void TextAppendRetPtr(char **text,  const char **append,  int **position)){TextAppend(*text, *append, *position);}                       // Append text at specific position and move cursor!
DECLARE(void TextFindIndexRetPtr(int *ret, const char **text,  const char **find)){*ret=TextFindIndex(*text, *find);}                                // Find first text occurrence within a string
DECLARE(void TextToUpperRetPtr(const char **ret, const char **text)){*ret=TextToUpper(*text);}                      // Get upper case version of provided string
DECLARE(void TextToLowerRetPtr(const char **ret, const char **text)){*ret=TextToLower(*text);}                      // Get lower case version of provided string
DECLARE(void TextToPascalRetPtr(const char **ret, const char **text)){*ret=TextToPascal(*text);}                     // Get Pascal case notation version of provided string
DECLARE(void TextToSnakeRetPtr(const char **ret, const char **text)){*ret=TextToSnake(*text);}                      // Get Snake case notation version of provided string
DECLARE(void TextToCamelRetPtr(const char **ret, const char **text)){*ret=TextToCamel(*text);}                      // Get Camel case notation version of provided string
DECLARE(void TextToIntegerRetPtr(int *ret, const char **text)){*ret=TextToInteger(*text);}                            // Get integer value from text (negative values not supported)
DECLARE(void TextToFloatRetPtr(float *ret, const char **text)){*ret=TextToFloat(*text);}                            // Get float value from text (negative values not supported)
DECLARE(void DrawLine3DRetPtr(Vector3 *startPos,  Vector3 *endPos,  Color *color)){DrawLine3D(*startPos, *endPos, *color);}                                    // Draw a line in 3D world space
DECLARE(void DrawPoint3DRetPtr(Vector3 *position,  Color *color)){DrawPoint3D(*position, *color);}                                                   // Draw a point in 3D space, actually a small line
DECLARE(void DrawCircle3DRetPtr(Vector3 *center,  float *radius,  Vector3 *rotationAxis,  float *rotationAngle,  Color *color)){DrawCircle3D(*center, *radius, *rotationAxis, *rotationAngle, *color);} // Draw a circle in 3D world space
DECLARE(void DrawTriangle3DRetPtr(Vector3 *v1,  Vector3 *v2,  Vector3 *v3,  Color *color)){DrawTriangle3D(*v1, *v2, *v3, *color);}                              // Draw a color-filled triangle (vertex in counter-clockwise order!)
DECLARE(void DrawTriangleStrip3DRetPtr(const Vector3 **points,  int *pointCount,  Color *color)){DrawTriangleStrip3D(*points, *pointCount, *color);}                      // Draw a triangle strip defined by points
DECLARE(void DrawCubeRetPtr(Vector3 *position,  float *width,  float *height,  float *length,  Color *color)){DrawCube(*position, *width, *height, *length, *color);}             // Draw cube
DECLARE(void DrawCubeVRetPtr(Vector3 *position,  Vector3 *size,  Color *color)){DrawCubeV(*position, *size, *color);}                                       // Draw cube (Vector version)
DECLARE(void DrawCubeWiresRetPtr(Vector3 *position,  float *width,  float *height,  float *length,  Color *color)){DrawCubeWires(*position, *width, *height, *length, *color);}        // Draw cube wires
DECLARE(void DrawCubeWiresVRetPtr(Vector3 *position,  Vector3 *size,  Color *color)){DrawCubeWiresV(*position, *size, *color);}                                  // Draw cube wires (Vector version)
DECLARE(void DrawSphereRetPtr(Vector3 *centerPos,  float *radius,  Color *color)){DrawSphere(*centerPos, *radius, *color);}                                     // Draw sphere
DECLARE(void DrawSphereExRetPtr(Vector3 *centerPos,  float *radius,  int *rings,  int *slices,  Color *color)){DrawSphereEx(*centerPos, *radius, *rings, *slices, *color);}            // Draw sphere with extended parameters
DECLARE(void DrawSphereWiresRetPtr(Vector3 *centerPos,  float *radius,  int *rings,  int *slices,  Color *color)){DrawSphereWires(*centerPos, *radius, *rings, *slices, *color);}         // Draw sphere wires
DECLARE(void DrawCylinderRetPtr(Vector3 *position,  float *radiusTop,  float *radiusBottom,  float *height,  int *slices,  Color *color)){DrawCylinder(*position, *radiusTop, *radiusBottom, *height, *slices, *color);} // Draw a cylinder/cone
DECLARE(void DrawCylinderExRetPtr(Vector3 *startPos,  Vector3 *endPos,  float *startRadius,  float *endRadius,  int *sides,  Color *color)){DrawCylinderEx(*startPos, *endPos, *startRadius, *endRadius, *sides, *color);} // Draw a cylinder with base at startPos and top at endPos
DECLARE(void DrawCylinderWiresRetPtr(Vector3 *position,  float *radiusTop,  float *radiusBottom,  float *height,  int *slices,  Color *color)){DrawCylinderWires(*position, *radiusTop, *radiusBottom, *height, *slices, *color);} // Draw a cylinder/cone wires
DECLARE(void DrawCylinderWiresExRetPtr(Vector3 *startPos,  Vector3 *endPos,  float *startRadius,  float *endRadius,  int *sides,  Color *color)){DrawCylinderWiresEx(*startPos, *endPos, *startRadius, *endRadius, *sides, *color);} // Draw a cylinder wires with base at startPos and top at endPos
DECLARE(void DrawCapsuleRetPtr(Vector3 *startPos,  Vector3 *endPos,  float *radius,  int *slices,  int *rings,  Color *color)){DrawCapsule(*startPos, *endPos, *radius, *slices, *rings, *color);} // Draw a capsule with the center of its sphere caps at startPos and endPos
DECLARE(void DrawCapsuleWiresRetPtr(Vector3 *startPos,  Vector3 *endPos,  float *radius,  int *slices,  int *rings,  Color *color)){DrawCapsuleWires(*startPos, *endPos, *radius, *slices, *rings, *color);} // Draw capsule wireframe with the center of its sphere caps at startPos and endPos
DECLARE(void DrawPlaneRetPtr(Vector3 *centerPos,  Vector2 *size,  Color *color)){DrawPlane(*centerPos, *size, *color);}                                      // Draw a plane XZ
DECLARE(void DrawRayRetPtr(Ray *ray,  Color *color)){DrawRay(*ray, *color);}                                                                // Draw a ray line
DECLARE(void DrawGridRetPtr(int *slices,  float *spacing)){DrawGrid(*slices, *spacing);}                                                          // Draw a grid (centered at (0, 0, 0))
DECLARE(void LoadModelRetPtr(Model *ret, const char **fileName)){*ret=LoadModel(*fileName);}                                                // Load model from files (meshes and materials)
DECLARE(void LoadModelFromMeshRetPtr(Model *ret, Mesh *mesh)){*ret=LoadModelFromMesh(*mesh);}                                                   // Load model from generated mesh (default material)
DECLARE(void IsModelValidRetPtr(bool *ret, Model *model)){*ret=IsModelValid(*model);}                                                       // Check if a model is valid (loaded in GPU, VAO/VBOs)
DECLARE(void UnloadModelRetPtr(Model *model)){UnloadModel(*model);}                                                        // Unload model (including meshes) from memory (RAM and/or VRAM)
DECLARE(void GetModelBoundingBoxRetPtr(BoundingBox *ret, Model *model)){*ret=GetModelBoundingBox(*model);}                                         // Compute model bounding box limits (considers all meshes)
DECLARE(void DrawModelRetPtr(Model *model,  Vector3 *position,  float *scale,  Color *tint)){DrawModel(*model, *position, *scale, *tint);}               // Draw a model (with texture if set)
DECLARE(void DrawModelExRetPtr(Model *model,  Vector3 *position,  Vector3 *rotationAxis,  float *rotationAngle,  Vector3 *scale,  Color *tint)){DrawModelEx(*model, *position, *rotationAxis, *rotationAngle, *scale, *tint);} // Draw a model with extended parameters
DECLARE(void DrawModelWiresRetPtr(Model *model,  Vector3 *position,  float *scale,  Color *tint)){DrawModelWires(*model, *position, *scale, *tint);}          // Draw a model wires (with texture if set)
DECLARE(void DrawModelWiresExRetPtr(Model *model,  Vector3 *position,  Vector3 *rotationAxis,  float *rotationAngle,  Vector3 *scale,  Color *tint)){DrawModelWiresEx(*model, *position, *rotationAxis, *rotationAngle, *scale, *tint);} // Draw a model wires (with texture if set) with extended parameters
DECLARE(void DrawModelPointsRetPtr(Model *model,  Vector3 *position,  float *scale,  Color *tint)){DrawModelPoints(*model, *position, *scale, *tint);} // Draw a model as points
DECLARE(void DrawModelPointsExRetPtr(Model *model,  Vector3 *position,  Vector3 *rotationAxis,  float *rotationAngle,  Vector3 *scale,  Color *tint)){DrawModelPointsEx(*model, *position, *rotationAxis, *rotationAngle, *scale, *tint);} // Draw a model as points with extended parameters
DECLARE(void DrawBoundingBoxRetPtr(BoundingBox *box,  Color *color)){DrawBoundingBox(*box, *color);}                                   // Draw bounding box (wires)
DECLARE(void DrawBillboardRetPtr(Camera *camera,  Texture2D *texture,  Vector3 *position,  float *scale,  Color *tint)){DrawBillboard(*camera, *texture, *position, *scale, *tint);}   // Draw a billboard texture
DECLARE(void DrawBillboardRecRetPtr(Camera *camera,  Texture2D *texture,  Rectangle *source,  Vector3 *position,  Vector2 *size,  Color *tint)){DrawBillboardRec(*camera, *texture, *source, *position, *size, *tint);} // Draw a billboard texture defined by source
DECLARE(void DrawBillboardProRetPtr(Camera *camera,  Texture2D *texture,  Rectangle *source,  Vector3 *position,  Vector3 *up,  Vector2 *size,  Vector2 *origin,  float *rotation,  Color *tint)){DrawBillboardPro(*camera, *texture, *source, *position, *up, *size, *origin, *rotation, *tint);} // Draw a billboard texture defined by source and rotation
DECLARE(void UploadMeshRetPtr(Mesh **mesh,  bool *dynamic)){UploadMesh(*mesh, *dynamic);}                                            // Upload mesh vertex data in GPU and provide VAO/VBO ids
DECLARE(void UpdateMeshBufferRetPtr(Mesh *mesh,  int *index,  const void **data,  int *dataSize,  int *offset)){UpdateMeshBuffer(*mesh, *index, *data, *dataSize, *offset);} // Update mesh vertex data in GPU for a specific buffer index
DECLARE(void UnloadMeshRetPtr(Mesh *mesh)){UnloadMesh(*mesh);}                                                           // Unload mesh data from CPU and GPU
DECLARE(void DrawMeshRetPtr(Mesh *mesh,  Material *material,  Matrix *transform)){DrawMesh(*mesh, *material, *transform);}                        // Draw a 3d mesh with material and transform
DECLARE(void DrawMeshInstancedRetPtr(Mesh *mesh,  Material *material,  const Matrix **transforms,  int *instances)){DrawMeshInstanced(*mesh, *material, *transforms, *instances);} // Draw multiple mesh instances with material and different transforms
DECLARE(void GetMeshBoundingBoxRetPtr(BoundingBox *ret, Mesh *mesh)){*ret=GetMeshBoundingBox(*mesh);}                                            // Compute mesh bounding box limits
DECLARE(void GenMeshTangentsRetPtr(Mesh **mesh)){GenMeshTangents(*mesh);}                                                     // Compute mesh tangents
DECLARE(void ExportMeshRetPtr(bool *ret, Mesh *mesh,  const char **fileName)){*ret=ExportMesh(*mesh, *fileName);}                                     // Export mesh data to file, returns true on success
DECLARE(void ExportMeshAsCodeRetPtr(bool *ret, Mesh *mesh,  const char **fileName)){*ret=ExportMeshAsCode(*mesh, *fileName);}                               // Export mesh as code file (.h) defining multiple arrays of vertex attributes
DECLARE(void GenMeshPolyRetPtr(Mesh *ret, int *sides,  float *radius)){*ret=GenMeshPoly(*sides, *radius);}                                            // Generate polygonal mesh
DECLARE(void GenMeshPlaneRetPtr(Mesh *ret, float *width,  float *length,  int *resX,  int *resZ)){*ret=GenMeshPlane(*width, *length, *resX, *resZ);}                     // Generate plane mesh (with subdivisions)
DECLARE(void GenMeshCubeRetPtr(Mesh *ret, float *width,  float *height,  float *length)){*ret=GenMeshCube(*width, *height, *length);}                            // Generate cuboid mesh
DECLARE(void GenMeshSphereRetPtr(Mesh *ret, float *radius,  int *rings,  int *slices)){*ret=GenMeshSphere(*radius, *rings, *slices);}                              // Generate sphere mesh (standard sphere)
DECLARE(void GenMeshHemiSphereRetPtr(Mesh *ret, float *radius,  int *rings,  int *slices)){*ret=GenMeshHemiSphere(*radius, *rings, *slices);}                          // Generate half-sphere mesh (no bottom cap)
DECLARE(void GenMeshCylinderRetPtr(Mesh *ret, float *radius,  float *height,  int *slices)){*ret=GenMeshCylinder(*radius, *height, *slices);}                         // Generate cylinder mesh
DECLARE(void GenMeshConeRetPtr(Mesh *ret, float *radius,  float *height,  int *slices)){*ret=GenMeshCone(*radius, *height, *slices);}                             // Generate cone/pyramid mesh
DECLARE(void GenMeshTorusRetPtr(Mesh *ret, float *radius,  float *size,  int *radSeg,  int *sides)){*ret=GenMeshTorus(*radius, *size, *radSeg, *sides);}                   // Generate torus mesh
DECLARE(void GenMeshKnotRetPtr(Mesh *ret, float *radius,  float *size,  int *radSeg,  int *sides)){*ret=GenMeshKnot(*radius, *size, *radSeg, *sides);}                    // Generate trefoil knot mesh
DECLARE(void GenMeshHeightmapRetPtr(Mesh *ret, Image *heightmap,  Vector3 *size)){*ret=GenMeshHeightmap(*heightmap, *size);}                                 // Generate heightmap mesh from image data
DECLARE(void GenMeshCubicmapRetPtr(Mesh *ret, Image *cubicmap,  Vector3 *cubeSize)){*ret=GenMeshCubicmap(*cubicmap, *cubeSize);}                               // Generate cubes-based map mesh from image data
DECLARE(void LoadMaterialsRetPtr(Material **ret, const char **fileName,  int **materialCount)){*ret=LoadMaterials(*fileName, *materialCount);}                    // Load materials from model file
DECLARE(void LoadMaterialDefaultRetPtr(Material *ret)){*ret=LoadMaterialDefault();}                                                   // Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
DECLARE(void IsMaterialValidRetPtr(bool *ret, Material *material)){*ret=IsMaterialValid(*material);}                                              // Check if a material is valid (shader assigned, map textures loaded in GPU)
DECLARE(void UnloadMaterialRetPtr(Material *material)){UnloadMaterial(*material);}                                               // Unload material from GPU memory (VRAM)
DECLARE(void SetMaterialTextureRetPtr(Material **material,  int *mapType,  Texture2D *texture)){SetMaterialTexture(*material, *mapType, *texture);}          // Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
DECLARE(void SetModelMeshMaterialRetPtr(Model **model,  int *meshId,  int *materialId)){SetModelMeshMaterial(*model, *meshId, *materialId);}                  // Set material for a mesh
DECLARE(void LoadModelAnimationsRetPtr(ModelAnimation **ret, const char **fileName,  int **animCount)){*ret=LoadModelAnimations(*fileName, *animCount);}            // Load model animations from file
DECLARE(void UpdateModelAnimationRetPtr(Model *model,  ModelAnimation *anim,  int *frame)){UpdateModelAnimation(*model, *anim, *frame);}               // Update model animation pose (CPU)
DECLARE(void UpdateModelAnimationBonesRetPtr(Model *model,  ModelAnimation *anim,  int *frame)){UpdateModelAnimationBones(*model, *anim, *frame);}          // Update model animation mesh bone matrices (GPU skinning)
DECLARE(void UnloadModelAnimationRetPtr(ModelAnimation *anim)){UnloadModelAnimation(*anim);}                                       // Unload animation data
DECLARE(void UnloadModelAnimationsRetPtr(ModelAnimation **animations,  int *animCount)){UnloadModelAnimations(*animations, *animCount);}                // Unload animation array data
DECLARE(void IsModelAnimationValidRetPtr(bool *ret, Model *model,  ModelAnimation *anim)){*ret=IsModelAnimationValid(*model, *anim);}                         // Check model animation skeleton match
DECLARE(void CheckCollisionSpheresRetPtr(bool *ret, Vector3 *center1,  float *radius1,  Vector3 *center2,  float *radius2)){*ret=CheckCollisionSpheres(*center1, *radius1, *center2, *radius2);}   // Check collision between two spheres
DECLARE(void CheckCollisionBoxesRetPtr(bool *ret, BoundingBox *box1,  BoundingBox *box2)){*ret=CheckCollisionBoxes(*box1, *box2);}                                 // Check collision between two bounding boxes
DECLARE(void CheckCollisionBoxSphereRetPtr(bool *ret, BoundingBox *box,  Vector3 *center,  float *radius)){*ret=CheckCollisionBoxSphere(*box, *center, *radius);}                  // Check collision between box and sphere
DECLARE(void GetRayCollisionSphereRetPtr(RayCollision *ret, Ray *ray,  Vector3 *center,  float *radius)){*ret=GetRayCollisionSphere(*ray, *center, *radius);}                    // Get collision info between ray and sphere
DECLARE(void GetRayCollisionBoxRetPtr(RayCollision *ret, Ray *ray,  BoundingBox *box)){*ret=GetRayCollisionBox(*ray, *box);}                                    // Get collision info between ray and box
DECLARE(void GetRayCollisionMeshRetPtr(RayCollision *ret, Ray *ray,  Mesh *mesh,  Matrix *transform)){*ret=GetRayCollisionMesh(*ray, *mesh, *transform);}                       // Get collision info between ray and mesh
DECLARE(void GetRayCollisionTriangleRetPtr(RayCollision *ret, Ray *ray,  Vector3 *p1,  Vector3 *p2,  Vector3 *p3)){*ret=GetRayCollisionTriangle(*ray, *p1, *p2, *p3);}            // Get collision info between ray and triangle
DECLARE(void GetRayCollisionQuadRetPtr(RayCollision *ret, Ray *ray,  Vector3 *p1,  Vector3 *p2,  Vector3 *p3,  Vector3 *p4)){*ret=GetRayCollisionQuad(*ray, *p1, *p2, *p3, *p4);}    // Get collision info between ray and quad
DECLARE(void InitAudioDeviceRetPtr()){InitAudioDevice();}                                     // Initialize audio device and context
DECLARE(void CloseAudioDeviceRetPtr()){CloseAudioDevice();}                                    // Close the audio device and context
DECLARE(void IsAudioDeviceReadyRetPtr(bool *ret)){*ret=IsAudioDeviceReady();}                                  // Check if audio device has been initialized successfully
DECLARE(void SetMasterVolumeRetPtr(float *volume)){SetMasterVolume(*volume);}                             // Set master volume (listener)
DECLARE(void GetMasterVolumeRetPtr(float *ret)){*ret=GetMasterVolume();}                                    // Get master volume (listener)
DECLARE(void LoadWaveRetPtr(Wave *ret, const char **fileName)){*ret=LoadWave(*fileName);}                            // Load wave data from file
DECLARE(void LoadWaveFromMemoryRetPtr(Wave *ret, const char **fileType,  const unsigned char **fileData,  int *dataSize)){*ret=LoadWaveFromMemory(*fileType, *fileData, *dataSize);} // Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
DECLARE(void IsWaveValidRetPtr(bool *ret, Wave *wave)){*ret=IsWaveValid(*wave);}                                    // Checks if wave data is valid (data loaded and parameters)
DECLARE(void LoadSoundRetPtr(Sound *ret, const char **fileName)){*ret=LoadSound(*fileName);}                          // Load sound from file
DECLARE(void LoadSoundFromWaveRetPtr(Sound *ret, Wave *wave)){*ret=LoadSoundFromWave(*wave);}                             // Load sound from wave data
DECLARE(void LoadSoundAliasRetPtr(Sound *ret, Sound *source)){*ret=LoadSoundAlias(*source);}                             // Create a new sound that shares the same sample data as the source sound, does not own the sound data
DECLARE(void IsSoundValidRetPtr(bool *ret, Sound *sound)){*ret=IsSoundValid(*sound);}                                 // Checks if a sound is valid (data loaded and buffers initialized)
DECLARE(void UpdateSoundRetPtr(Sound *sound,  const void **data,  int *sampleCount)){UpdateSound(*sound, *data, *sampleCount);} // Update sound buffer with new data
DECLARE(void UnloadWaveRetPtr(Wave *wave)){UnloadWave(*wave);}                                     // Unload wave data
DECLARE(void UnloadSoundRetPtr(Sound *sound)){UnloadSound(*sound);}                                  // Unload sound
DECLARE(void UnloadSoundAliasRetPtr(Sound *alias)){UnloadSoundAlias(*alias);}                             // Unload a sound alias (does not deallocate sample data)
DECLARE(void ExportWaveRetPtr(bool *ret, Wave *wave,  const char **fileName)){*ret=ExportWave(*wave, *fileName);}               // Export wave data to file, returns true on success
DECLARE(void ExportWaveAsCodeRetPtr(bool *ret, Wave *wave,  const char **fileName)){*ret=ExportWaveAsCode(*wave, *fileName);}         // Export wave sample data to code (.h), returns true on success
DECLARE(void PlaySoundRetPtr(Sound *sound)){PlaySound(*sound);}                                    // Play a sound
DECLARE(void StopSoundRetPtr(Sound *sound)){StopSound(*sound);}                                    // Stop playing a sound
DECLARE(void PauseSoundRetPtr(Sound *sound)){PauseSound(*sound);}                                   // Pause a sound
DECLARE(void ResumeSoundRetPtr(Sound *sound)){ResumeSound(*sound);}                                  // Resume a paused sound
DECLARE(void IsSoundPlayingRetPtr(bool *ret, Sound *sound)){*ret=IsSoundPlaying(*sound);}                               // Check if a sound is currently playing
DECLARE(void SetSoundVolumeRetPtr(Sound *sound,  float *volume)){SetSoundVolume(*sound, *volume);}                 // Set volume for a sound (1.0 is max level)
DECLARE(void SetSoundPitchRetPtr(Sound *sound,  float *pitch)){SetSoundPitch(*sound, *pitch);}                   // Set pitch for a sound (1.0 is base level)
DECLARE(void SetSoundPanRetPtr(Sound *sound,  float *pan)){SetSoundPan(*sound, *pan);}                       // Set pan for a sound (0.5 is center)
DECLARE(void WaveCopyRetPtr(Wave *ret, Wave *wave)){*ret=WaveCopy(*wave);}                                       // Copy a wave to a new wave
DECLARE(void WaveCropRetPtr(Wave **wave,  int *initFrame,  int *finalFrame)){WaveCrop(*wave, *initFrame, *finalFrame);}       // Crop a wave to defined frames range
DECLARE(void WaveFormatRetPtr(Wave **wave,  int *sampleRate,  int *sampleSize,  int *channels)){WaveFormat(*wave, *sampleRate, *sampleSize, *channels);} // Convert wave data to desired format
DECLARE(void LoadWaveSamplesRetPtr(float **ret, Wave *wave)){*ret=LoadWaveSamples(*wave);}                              // Load samples data from wave as a 32bit float data array
DECLARE(void UnloadWaveSamplesRetPtr(float **samples)){UnloadWaveSamples(*samples);}                         // Unload samples data loaded with LoadWaveSamples()
DECLARE(void LoadMusicStreamRetPtr(Music *ret, const char **fileName)){*ret=LoadMusicStream(*fileName);}                    // Load music stream from file
DECLARE(void LoadMusicStreamFromMemoryRetPtr(Music *ret, const char **fileType,  const unsigned char **data,  int *dataSize)){*ret=LoadMusicStreamFromMemory(*fileType, *data, *dataSize);} // Load music stream from data
DECLARE(void IsMusicValidRetPtr(bool *ret, Music *music)){*ret=IsMusicValid(*music);}                                 // Checks if a music stream is valid (context and buffers initialized)
DECLARE(void UnloadMusicStreamRetPtr(Music *music)){UnloadMusicStream(*music);}                            // Unload music stream
DECLARE(void PlayMusicStreamRetPtr(Music *music)){PlayMusicStream(*music);}                              // Start music playing
DECLARE(void IsMusicStreamPlayingRetPtr(bool *ret, Music *music)){*ret=IsMusicStreamPlaying(*music);}                         // Check if music is playing
DECLARE(void UpdateMusicStreamRetPtr(Music *music)){UpdateMusicStream(*music);}                            // Updates buffers for music streaming
DECLARE(void StopMusicStreamRetPtr(Music *music)){StopMusicStream(*music);}                              // Stop music playing
DECLARE(void PauseMusicStreamRetPtr(Music *music)){PauseMusicStream(*music);}                             // Pause music playing
DECLARE(void ResumeMusicStreamRetPtr(Music *music)){ResumeMusicStream(*music);}                            // Resume playing paused music
DECLARE(void SeekMusicStreamRetPtr(Music *music,  float *position)){SeekMusicStream(*music, *position);}              // Seek music to a position (in seconds)
DECLARE(void SetMusicVolumeRetPtr(Music *music,  float *volume)){SetMusicVolume(*music, *volume);}                 // Set volume for music (1.0 is max level)
DECLARE(void SetMusicPitchRetPtr(Music *music,  float *pitch)){SetMusicPitch(*music, *pitch);}                   // Set pitch for a music (1.0 is base level)
DECLARE(void SetMusicPanRetPtr(Music *music,  float *pan)){SetMusicPan(*music, *pan);}                       // Set pan for a music (0.5 is center)
DECLARE(void GetMusicTimeLengthRetPtr(float *ret, Music *music)){*ret=GetMusicTimeLength(*music);}                          // Get music time length (in seconds)
DECLARE(void GetMusicTimePlayedRetPtr(float *ret, Music *music)){*ret=GetMusicTimePlayed(*music);}                          // Get current music time played (in seconds)
DECLARE(void LoadAudioStreamRetPtr(AudioStream *ret, unsigned int *sampleRate,  unsigned int *sampleSize,  unsigned int *channels)){*ret=LoadAudioStream(*sampleRate, *sampleSize, *channels);} // Load audio stream (to stream raw audio pcm data)
DECLARE(void IsAudioStreamValidRetPtr(bool *ret, AudioStream *stream)){*ret=IsAudioStreamValid(*stream);}                    // Checks if an audio stream is valid (buffers initialized)
DECLARE(void UnloadAudioStreamRetPtr(AudioStream *stream)){UnloadAudioStream(*stream);}                     // Unload audio stream and free memory
DECLARE(void UpdateAudioStreamRetPtr(AudioStream *stream,  const void **data,  int *frameCount)){UpdateAudioStream(*stream, *data, *frameCount);} // Update audio stream buffers with data
DECLARE(void IsAudioStreamProcessedRetPtr(bool *ret, AudioStream *stream)){*ret=IsAudioStreamProcessed(*stream);}                // Check if any audio stream buffers requires refill
DECLARE(void PlayAudioStreamRetPtr(AudioStream *stream)){PlayAudioStream(*stream);}                       // Play audio stream
DECLARE(void PauseAudioStreamRetPtr(AudioStream *stream)){PauseAudioStream(*stream);}                      // Pause audio stream
DECLARE(void ResumeAudioStreamRetPtr(AudioStream *stream)){ResumeAudioStream(*stream);}                     // Resume audio stream
DECLARE(void IsAudioStreamPlayingRetPtr(bool *ret, AudioStream *stream)){*ret=IsAudioStreamPlaying(*stream);}                  // Check if audio stream is playing
DECLARE(void StopAudioStreamRetPtr(AudioStream *stream)){StopAudioStream(*stream);}                       // Stop audio stream
DECLARE(void SetAudioStreamVolumeRetPtr(AudioStream *stream,  float *volume)){SetAudioStreamVolume(*stream, *volume);}    // Set volume for audio stream (1.0 is max level)
DECLARE(void SetAudioStreamPitchRetPtr(AudioStream *stream,  float *pitch)){SetAudioStreamPitch(*stream, *pitch);}      // Set pitch for audio stream (1.0 is base level)
DECLARE(void SetAudioStreamPanRetPtr(AudioStream *stream,  float *pan)){SetAudioStreamPan(*stream, *pan);}          // Set pan for audio stream (0.5 is centered)
DECLARE(void SetAudioStreamBufferSizeDefaultRetPtr(int *size)){SetAudioStreamBufferSizeDefault(*size);}                 // Default size for new audio streams
DECLARE(void SetAudioStreamCallbackRetPtr(AudioStream *stream,  AudioCallback *callback)){SetAudioStreamCallback(*stream, *callback);} // Audio thread callback to request new data
DECLARE(void AttachAudioStreamProcessorRetPtr(AudioStream *stream,  AudioCallback *processor)){AttachAudioStreamProcessor(*stream, *processor);} // Attach audio stream processor to stream, receives the samples as 'float'
DECLARE(void DetachAudioStreamProcessorRetPtr(AudioStream *stream,  AudioCallback *processor)){DetachAudioStreamProcessor(*stream, *processor);} // Detach audio stream processor from stream
DECLARE(void AttachAudioMixedProcessorRetPtr(AudioCallback *processor)){AttachAudioMixedProcessor(*processor);} // Attach audio stream processor to the entire audio pipeline, receives the samples as 'float'
DECLARE(void DetachAudioMixedProcessorRetPtr(AudioCallback *processor)){DetachAudioMixedProcessor(*processor);} // Detach audio stream processor from the entire audio pipeline
DECLARE(void ClampRetPtr(float *ret, float *value,  float *min,  float *max)){*ret=Clamp(*value, *min, *max);}
DECLARE(void LerpRetPtr(float *ret, float *start,  float *end,  float *amount)){*ret=Lerp(*start, *end, *amount);}
DECLARE(void NormalizeRetPtr(float *ret, float *value,  float *start,  float *end)){*ret=Normalize(*value, *start, *end);}
DECLARE(void RemapRetPtr(float *ret, float *value,  float *inputStart,  float *inputEnd,  float *outputStart,  float *outputEnd)){*ret=Remap(*value, *inputStart, *inputEnd, *outputStart, *outputEnd);}
DECLARE(void WrapRetPtr(float *ret, float *value,  float *min,  float *max)){*ret=Wrap(*value, *min, *max);}
DECLARE(void FloatEqualsRetPtr(int *ret, float *x,  float *y)){*ret=FloatEquals(*x, *y);}
DECLARE(void Vector2ZeroRetPtr(Vector2 *ret)){*ret=Vector2Zero();}
DECLARE(void Vector2OneRetPtr(Vector2 *ret)){*ret=Vector2One();}
DECLARE(void Vector2AddRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Add(*v1, *v2);}
DECLARE(void Vector2AddValueRetPtr(Vector2 *ret, Vector2 *v,  float *add)){*ret=Vector2AddValue(*v, *add);}
DECLARE(void Vector2SubtractRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Subtract(*v1, *v2);}
DECLARE(void Vector2SubtractValueRetPtr(Vector2 *ret, Vector2 *v,  float *sub)){*ret=Vector2SubtractValue(*v, *sub);}
DECLARE(void Vector2LengthRetPtr(float *ret, Vector2 *v)){*ret=Vector2Length(*v);}
DECLARE(void Vector2LengthSqrRetPtr(float *ret, Vector2 *v)){*ret=Vector2LengthSqr(*v);}
DECLARE(void Vector2DotProductRetPtr(float *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2DotProduct(*v1, *v2);}
DECLARE(void Vector2DistanceRetPtr(float *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Distance(*v1, *v2);}
DECLARE(void Vector2DistanceSqrRetPtr(float *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2DistanceSqr(*v1, *v2);}
DECLARE(void Vector2AngleRetPtr(float *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Angle(*v1, *v2);}
DECLARE(void Vector2LineAngleRetPtr(float *ret, Vector2 *start,  Vector2 *end)){*ret=Vector2LineAngle(*start, *end);}
DECLARE(void Vector2ScaleRetPtr(Vector2 *ret, Vector2 *v,  float *scale)){*ret=Vector2Scale(*v, *scale);}
DECLARE(void Vector2MultiplyRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Multiply(*v1, *v2);}
DECLARE(void Vector2NegateRetPtr(Vector2 *ret, Vector2 *v)){*ret=Vector2Negate(*v);}
DECLARE(void Vector2DivideRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Divide(*v1, *v2);}
DECLARE(void Vector2NormalizeRetPtr(Vector2 *ret, Vector2 *v)){*ret=Vector2Normalize(*v);}
DECLARE(void Vector2TransformRetPtr(Vector2 *ret, Vector2 *v,  Matrix *mat)){*ret=Vector2Transform(*v, *mat);}
DECLARE(void Vector2LerpRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2,  float *amount)){*ret=Vector2Lerp(*v1, *v2, *amount);}
DECLARE(void Vector2ReflectRetPtr(Vector2 *ret, Vector2 *v,  Vector2 *normal)){*ret=Vector2Reflect(*v, *normal);}
DECLARE(void Vector2MinRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Min(*v1, *v2);}
DECLARE(void Vector2MaxRetPtr(Vector2 *ret, Vector2 *v1,  Vector2 *v2)){*ret=Vector2Max(*v1, *v2);}
DECLARE(void Vector2RotateRetPtr(Vector2 *ret, Vector2 *v,  float *angle)){*ret=Vector2Rotate(*v, *angle);}
DECLARE(void Vector2MoveTowardsRetPtr(Vector2 *ret, Vector2 *v,  Vector2 *target,  float *maxDistance)){*ret=Vector2MoveTowards(*v, *target, *maxDistance);}
DECLARE(void Vector2InvertRetPtr(Vector2 *ret, Vector2 *v)){*ret=Vector2Invert(*v);}
DECLARE(void Vector2ClampRetPtr(Vector2 *ret, Vector2 *v,  Vector2 *min,  Vector2 *max)){*ret=Vector2Clamp(*v, *min, *max);}
DECLARE(void Vector2ClampValueRetPtr(Vector2 *ret, Vector2 *v,  float *min,  float *max)){*ret=Vector2ClampValue(*v, *min, *max);}
DECLARE(void Vector2EqualsRetPtr(int *ret, Vector2 *p,  Vector2 *q)){*ret=Vector2Equals(*p, *q);}
DECLARE(void Vector2RefractRetPtr(Vector2 *ret, Vector2 *v,  Vector2 *n,  float *r)){*ret=Vector2Refract(*v, *n, *r);}
DECLARE(void Vector3ZeroRetPtr(Vector3 *ret)){*ret=Vector3Zero();}
DECLARE(void Vector3OneRetPtr(Vector3 *ret)){*ret=Vector3One();}
DECLARE(void Vector3AddRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Add(*v1, *v2);}
DECLARE(void Vector3AddValueRetPtr(Vector3 *ret, Vector3 *v,  float *add)){*ret=Vector3AddValue(*v, *add);}
DECLARE(void Vector3SubtractRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Subtract(*v1, *v2);}
DECLARE(void Vector3SubtractValueRetPtr(Vector3 *ret, Vector3 *v,  float *sub)){*ret=Vector3SubtractValue(*v, *sub);}
DECLARE(void Vector3ScaleRetPtr(Vector3 *ret, Vector3 *v,  float *scalar)){*ret=Vector3Scale(*v, *scalar);}
DECLARE(void Vector3MultiplyRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Multiply(*v1, *v2);}
DECLARE(void Vector3CrossProductRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3CrossProduct(*v1, *v2);}
DECLARE(void Vector3PerpendicularRetPtr(Vector3 *ret, Vector3 *v)){*ret=Vector3Perpendicular(*v);}
DECLARE(void Vector3LengthRetPtr(float *ret, const Vector3 *v)){*ret=Vector3Length(*v);}
DECLARE(void Vector3LengthSqrRetPtr(float *ret, const Vector3 *v)){*ret=Vector3LengthSqr(*v);}
DECLARE(void Vector3DotProductRetPtr(float *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3DotProduct(*v1, *v2);}
DECLARE(void Vector3DistanceRetPtr(float *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Distance(*v1, *v2);}
DECLARE(void Vector3DistanceSqrRetPtr(float *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3DistanceSqr(*v1, *v2);}
DECLARE(void Vector3AngleRetPtr(float *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Angle(*v1, *v2);}
DECLARE(void Vector3NegateRetPtr(Vector3 *ret, Vector3 *v)){*ret=Vector3Negate(*v);}
DECLARE(void Vector3DivideRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Divide(*v1, *v2);}
DECLARE(void Vector3NormalizeRetPtr(Vector3 *ret, Vector3 *v)){*ret=Vector3Normalize(*v);}
DECLARE(void Vector3ProjectRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Project(*v1, *v2);}
DECLARE(void Vector3RejectRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Reject(*v1, *v2);}
DECLARE(void Vector3OrthoNormalizeRetPtr(Vector3 **v1,  Vector3 **v2)){Vector3OrthoNormalize(*v1, *v2);}
DECLARE(void Vector3TransformRetPtr(Vector3 *ret, Vector3 *v,  Matrix *mat)){*ret=Vector3Transform(*v, *mat);}
DECLARE(void Vector3RotateByQuaternionRetPtr(Vector3 *ret, Vector3 *v,  Quaternion *q)){*ret=Vector3RotateByQuaternion(*v, *q);}
DECLARE(void Vector3RotateByAxisAngleRetPtr(Vector3 *ret, Vector3 *v,  Vector3 *axis,  float *angle)){*ret=Vector3RotateByAxisAngle(*v, *axis, *angle);}
DECLARE(void Vector3MoveTowardsRetPtr(Vector3 *ret, Vector3 *v,  Vector3 *target,  float *maxDistance)){*ret=Vector3MoveTowards(*v, *target, *maxDistance);}
DECLARE(void Vector3LerpRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2,  float *amount)){*ret=Vector3Lerp(*v1, *v2, *amount);}
DECLARE(void Vector3CubicHermiteRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *tangent1,  Vector3 *v2,  Vector3 *tangent2,  float *amount)){*ret=Vector3CubicHermite(*v1, *tangent1, *v2, *tangent2, *amount);}
DECLARE(void Vector3ReflectRetPtr(Vector3 *ret, Vector3 *v,  Vector3 *normal)){*ret=Vector3Reflect(*v, *normal);}
DECLARE(void Vector3MinRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Min(*v1, *v2);}
DECLARE(void Vector3MaxRetPtr(Vector3 *ret, Vector3 *v1,  Vector3 *v2)){*ret=Vector3Max(*v1, *v2);}
DECLARE(void Vector3BarycenterRetPtr(Vector3 *ret, Vector3 *p,  Vector3 *a,  Vector3 *b,  Vector3 *c)){*ret=Vector3Barycenter(*p, *a, *b, *c);}
DECLARE(void Vector3UnprojectRetPtr(Vector3 *ret, Vector3 *source,  Matrix *projection,  Matrix *view)){*ret=Vector3Unproject(*source, *projection, *view);}
DECLARE(void Vector3ToFloatVRetPtr(float3 *ret, Vector3 *v)){*ret=Vector3ToFloatV(*v);}
DECLARE(void Vector3InvertRetPtr(Vector3 *ret, Vector3 *v)){*ret=Vector3Invert(*v);}
DECLARE(void Vector3ClampRetPtr(Vector3 *ret, Vector3 *v,  Vector3 *min,  Vector3 *max)){*ret=Vector3Clamp(*v, *min, *max);}
DECLARE(void Vector3ClampValueRetPtr(Vector3 *ret, Vector3 *v,  float *min,  float *max)){*ret=Vector3ClampValue(*v, *min, *max);}
DECLARE(void Vector3EqualsRetPtr(int *ret, Vector3 *p,  Vector3 *q)){*ret=Vector3Equals(*p, *q);}
DECLARE(void Vector3RefractRetPtr(Vector3 *ret, Vector3 *v,  Vector3 *n,  float *r)){*ret=Vector3Refract(*v, *n, *r);}
DECLARE(void Vector4ZeroRetPtr(Vector4 *ret)){*ret=Vector4Zero();}
DECLARE(void Vector4OneRetPtr(Vector4 *ret)){*ret=Vector4One();}
DECLARE(void Vector4AddRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Add(*v1, *v2);}
DECLARE(void Vector4AddValueRetPtr(Vector4 *ret, Vector4 *v,  float *add)){*ret=Vector4AddValue(*v, *add);}
DECLARE(void Vector4SubtractRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Subtract(*v1, *v2);}
DECLARE(void Vector4SubtractValueRetPtr(Vector4 *ret, Vector4 *v,  float *add)){*ret=Vector4SubtractValue(*v, *add);}
DECLARE(void Vector4LengthRetPtr(float *ret, Vector4 *v)){*ret=Vector4Length(*v);}
DECLARE(void Vector4LengthSqrRetPtr(float *ret, Vector4 *v)){*ret=Vector4LengthSqr(*v);}
DECLARE(void Vector4DotProductRetPtr(float *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4DotProduct(*v1, *v2);}
DECLARE(void Vector4DistanceRetPtr(float *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Distance(*v1, *v2);}
DECLARE(void Vector4DistanceSqrRetPtr(float *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4DistanceSqr(*v1, *v2);}
DECLARE(void Vector4ScaleRetPtr(Vector4 *ret, Vector4 *v,  float *scale)){*ret=Vector4Scale(*v, *scale);}
DECLARE(void Vector4MultiplyRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Multiply(*v1, *v2);}
DECLARE(void Vector4NegateRetPtr(Vector4 *ret, Vector4 *v)){*ret=Vector4Negate(*v);}
DECLARE(void Vector4DivideRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Divide(*v1, *v2);}
DECLARE(void Vector4NormalizeRetPtr(Vector4 *ret, Vector4 *v)){*ret=Vector4Normalize(*v);}
DECLARE(void Vector4MinRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Min(*v1, *v2);}
DECLARE(void Vector4MaxRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2)){*ret=Vector4Max(*v1, *v2);}
DECLARE(void Vector4LerpRetPtr(Vector4 *ret, Vector4 *v1,  Vector4 *v2,  float *amount)){*ret=Vector4Lerp(*v1, *v2, *amount);}
DECLARE(void Vector4MoveTowardsRetPtr(Vector4 *ret, Vector4 *v,  Vector4 *target,  float *maxDistance)){*ret=Vector4MoveTowards(*v, *target, *maxDistance);}
DECLARE(void Vector4InvertRetPtr(Vector4 *ret, Vector4 *v)){*ret=Vector4Invert(*v);}
DECLARE(void Vector4EqualsRetPtr(int *ret, Vector4 *p,  Vector4 *q)){*ret=Vector4Equals(*p, *q);}
DECLARE(void MatrixDeterminantRetPtr(float *ret, Matrix *mat)){*ret=MatrixDeterminant(*mat);}
DECLARE(void MatrixTraceRetPtr(float *ret, Matrix *mat)){*ret=MatrixTrace(*mat);}
DECLARE(void MatrixTransposeRetPtr(Matrix *ret, Matrix *mat)){*ret=MatrixTranspose(*mat);}
DECLARE(void MatrixInvertRetPtr(Matrix *ret, Matrix *mat)){*ret=MatrixInvert(*mat);}
DECLARE(void MatrixIdentityRetPtr(Matrix *ret)){*ret=MatrixIdentity();}
DECLARE(void MatrixAddRetPtr(Matrix *ret, Matrix *left,  Matrix *right)){*ret=MatrixAdd(*left, *right);}
DECLARE(void MatrixSubtractRetPtr(Matrix *ret, Matrix *left,  Matrix *right)){*ret=MatrixSubtract(*left, *right);}
DECLARE(void MatrixMultiplyRetPtr(Matrix *ret, Matrix *left,  Matrix *right)){*ret=MatrixMultiply(*left, *right);}
DECLARE(void MatrixTranslateRetPtr(Matrix *ret, float *x,  float *y,  float *z)){*ret=MatrixTranslate(*x, *y, *z);}
DECLARE(void MatrixRotateRetPtr(Matrix *ret, Vector3 *axis,  float *angle)){*ret=MatrixRotate(*axis, *angle);}
DECLARE(void MatrixRotateXRetPtr(Matrix *ret, float *angle)){*ret=MatrixRotateX(*angle);}
DECLARE(void MatrixRotateYRetPtr(Matrix *ret, float *angle)){*ret=MatrixRotateY(*angle);}
DECLARE(void MatrixRotateZRetPtr(Matrix *ret, float *angle)){*ret=MatrixRotateZ(*angle);}
DECLARE(void MatrixRotateXYZRetPtr(Matrix *ret, Vector3 *angle)){*ret=MatrixRotateXYZ(*angle);}
DECLARE(void MatrixRotateZYXRetPtr(Matrix *ret, Vector3 *angle)){*ret=MatrixRotateZYX(*angle);}
DECLARE(void MatrixScaleRetPtr(Matrix *ret, float *x,  float *y,  float *z)){*ret=MatrixScale(*x, *y, *z);}
DECLARE(void MatrixFrustumRetPtr(Matrix *ret, double *left,  double *right,  double *bottom,  double *top,  double *nearPlane,  double *farPlane)){*ret=MatrixFrustum(*left, *right, *bottom, *top, *nearPlane, *farPlane);}
DECLARE(void MatrixPerspectiveRetPtr(Matrix *ret, double *fovY,  double *aspect,  double *nearPlane,  double *farPlane)){*ret=MatrixPerspective(*fovY, *aspect, *nearPlane, *farPlane);}
DECLARE(void MatrixOrthoRetPtr(Matrix *ret, double *left,  double *right,  double *bottom,  double *top,  double *nearPlane,  double *farPlane)){*ret=MatrixOrtho(*left, *right, *bottom, *top, *nearPlane, *farPlane);}
DECLARE(void MatrixLookAtRetPtr(Matrix *ret, Vector3 *eye,  Vector3 *target,  Vector3 *up)){*ret=MatrixLookAt(*eye, *target, *up);}
DECLARE(void MatrixToFloatVRetPtr(float16 *ret, Matrix *mat)){*ret=MatrixToFloatV(*mat);}
DECLARE(void QuaternionAddRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2)){*ret=QuaternionAdd(*q1, *q2);}
DECLARE(void QuaternionAddValueRetPtr(Quaternion *ret, Quaternion *q,  float *add)){*ret=QuaternionAddValue(*q, *add);}
DECLARE(void QuaternionSubtractRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2)){*ret=QuaternionSubtract(*q1, *q2);}
DECLARE(void QuaternionSubtractValueRetPtr(Quaternion *ret, Quaternion *q,  float *sub)){*ret=QuaternionSubtractValue(*q, *sub);}
DECLARE(void QuaternionIdentityRetPtr(Quaternion *ret)){*ret=QuaternionIdentity();}
DECLARE(void QuaternionLengthRetPtr(float *ret, Quaternion *q)){*ret=QuaternionLength(*q);}
DECLARE(void QuaternionNormalizeRetPtr(Quaternion *ret, Quaternion *q)){*ret=QuaternionNormalize(*q);}
DECLARE(void QuaternionInvertRetPtr(Quaternion *ret, Quaternion *q)){*ret=QuaternionInvert(*q);}
DECLARE(void QuaternionMultiplyRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2)){*ret=QuaternionMultiply(*q1, *q2);}
DECLARE(void QuaternionScaleRetPtr(Quaternion *ret, Quaternion *q,  float *mul)){*ret=QuaternionScale(*q, *mul);}
DECLARE(void QuaternionDivideRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2)){*ret=QuaternionDivide(*q1, *q2);}
DECLARE(void QuaternionLerpRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2,  float *amount)){*ret=QuaternionLerp(*q1, *q2, *amount);}
DECLARE(void QuaternionNlerpRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2,  float *amount)){*ret=QuaternionNlerp(*q1, *q2, *amount);}
DECLARE(void QuaternionSlerpRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *q2,  float *amount)){*ret=QuaternionSlerp(*q1, *q2, *amount);}
DECLARE(void QuaternionCubicHermiteSplineRetPtr(Quaternion *ret, Quaternion *q1,  Quaternion *outTangent1,  Quaternion *q2,  Quaternion *inTangent2,  float *t)){*ret=QuaternionCubicHermiteSpline(*q1, *outTangent1, *q2, *inTangent2, *t);}
DECLARE(void QuaternionFromVector3ToVector3RetPtr(Quaternion *ret, Vector3 *from,  Vector3 *to)){*ret=QuaternionFromVector3ToVector3(*from, *to);}
DECLARE(void QuaternionFromMatrixRetPtr(Quaternion *ret, Matrix *mat)){*ret=QuaternionFromMatrix(*mat);}
DECLARE(void QuaternionToMatrixRetPtr(Matrix *ret, Quaternion *q)){*ret=QuaternionToMatrix(*q);}
DECLARE(void QuaternionFromAxisAngleRetPtr(Quaternion *ret, Vector3 *axis,  float *angle)){*ret=QuaternionFromAxisAngle(*axis, *angle);}
DECLARE(void QuaternionToAxisAngleRetPtr(Quaternion *q,  Vector3 **outAxis,  float **outAngle)){QuaternionToAxisAngle(*q, *outAxis, *outAngle);}
DECLARE(void QuaternionFromEulerRetPtr(Quaternion *ret, float *pitch,  float *yaw,  float *roll)){*ret=QuaternionFromEuler(*pitch, *yaw, *roll);}
DECLARE(void QuaternionToEulerRetPtr(Vector3 *ret, Quaternion *q)){*ret=QuaternionToEuler(*q);}
DECLARE(void QuaternionTransformRetPtr(Quaternion *ret, Quaternion *q,  Matrix *mat)){*ret=QuaternionTransform(*q, *mat);}
DECLARE(void QuaternionEqualsRetPtr(int *ret, Quaternion *p,  Quaternion *q)){*ret=QuaternionEquals(*p, *q);}
DECLARE(void MatrixDecomposeRetPtr(Matrix *mat,  Vector3 **translation,  Quaternion **rotation,  Vector3 **scale)){MatrixDecompose(*mat, *translation, *rotation, *scale);}
DECLARE(void rlMatrixModeRetPtr(int *mode)){rlMatrixMode(*mode);}                      // Choose the current matrix to be transformed
DECLARE(void rlPushMatrixRetPtr()){rlPushMatrix();}                          // Push the current matrix to stack
DECLARE(void rlPopMatrixRetPtr()){rlPopMatrix();}                           // Pop latest inserted matrix from stack
DECLARE(void rlLoadIdentityRetPtr()){rlLoadIdentity();}                        // Reset current matrix to identity matrix
DECLARE(void rlTranslatefRetPtr(float *x,  float *y,  float *z)){rlTranslatef(*x, *y, *z);}     // Multiply the current matrix by a translation matrix
DECLARE(void rlRotatefRetPtr(float *angle,  float *x,  float *y,  float *z)){rlRotatef(*angle, *x, *y, *z);} // Multiply the current matrix by a rotation matrix
DECLARE(void rlScalefRetPtr(float *x,  float *y,  float *z)){rlScalef(*x, *y, *z);}         // Multiply the current matrix by a scaling matrix
DECLARE(void rlMultMatrixfRetPtr(const float **matf)){rlMultMatrixf(*matf);}            // Multiply the current matrix by another matrix
DECLARE(void rlFrustumRetPtr(double *left,  double *right,  double *bottom,  double *top,  double *znear,  double *zfar)){rlFrustum(*left, *right, *bottom, *top, *znear, *zfar);}
DECLARE(void rlOrthoRetPtr(double *left,  double *right,  double *bottom,  double *top,  double *znear,  double *zfar)){rlOrtho(*left, *right, *bottom, *top, *znear, *zfar);}
DECLARE(void rlViewportRetPtr(int *x,  int *y,  int *width,  int *height)){rlViewport(*x, *y, *width, *height);} // Set the viewport area
DECLARE(void rlSetClipPlanesRetPtr(double *nearPlane,  double *farPlane)){rlSetClipPlanes(*nearPlane, *farPlane);}    // Set clip planes distances
DECLARE(void rlGetCullDistanceNearRetPtr(double *ret)){*ret=rlGetCullDistanceNear();}               // Get cull plane distance near
DECLARE(void rlGetCullDistanceFarRetPtr(double *ret)){*ret=rlGetCullDistanceFar();}                // Get cull plane distance far
DECLARE(void rlBeginRetPtr(int *mode)){rlBegin(*mode);}                           // Initialize drawing mode (how to organize vertex)
DECLARE(void rlEndRetPtr()){rlEnd();}                                 // Finish vertex providing
DECLARE(void rlVertex2iRetPtr(int *x,  int *y)){rlVertex2i(*x, *y);}                    // Define one vertex (position) - 2 int
DECLARE(void rlVertex2fRetPtr(float *x,  float *y)){rlVertex2f(*x, *y);}                // Define one vertex (position) - 2 float
DECLARE(void rlVertex3fRetPtr(float *x,  float *y,  float *z)){rlVertex3f(*x, *y, *z);}       // Define one vertex (position) - 3 float
DECLARE(void rlTexCoord2fRetPtr(float *x,  float *y)){rlTexCoord2f(*x, *y);}              // Define one vertex (texture coordinate) - 2 float
DECLARE(void rlNormal3fRetPtr(float *x,  float *y,  float *z)){rlNormal3f(*x, *y, *z);}       // Define one vertex (normal) - 3 float
DECLARE(void rlColor4ubRetPtr(unsigned char *r,  unsigned char *g,  unsigned char *b,  unsigned char *a)){rlColor4ub(*r, *g, *b, *a);} // Define one vertex (color) - 4 byte
DECLARE(void rlColor3fRetPtr(float *x,  float *y,  float *z)){rlColor3f(*x, *y, *z);}        // Define one vertex (color) - 3 float
DECLARE(void rlColor4fRetPtr(float *x,  float *y,  float *z,  float *w)){rlColor4f(*x, *y, *z, *w);} // Define one vertex (color) - 4 float
DECLARE(void rlEnableVertexArrayRetPtr(bool *ret, unsigned int *vaoId)){*ret=rlEnableVertexArray(*vaoId);}     // Enable vertex array (VAO, if supported)
DECLARE(void rlDisableVertexArrayRetPtr()){rlDisableVertexArray();}                  // Disable vertex array (VAO, if supported)
DECLARE(void rlEnableVertexBufferRetPtr(unsigned int *id)){rlEnableVertexBuffer(*id);}       // Enable vertex buffer (VBO)
DECLARE(void rlDisableVertexBufferRetPtr()){rlDisableVertexBuffer();}                 // Disable vertex buffer (VBO)
DECLARE(void rlEnableVertexBufferElementRetPtr(unsigned int *id)){rlEnableVertexBufferElement(*id);} // Enable vertex buffer element (VBO element)
DECLARE(void rlDisableVertexBufferElementRetPtr()){rlDisableVertexBufferElement();}          // Disable vertex buffer element (VBO element)
DECLARE(void rlEnableVertexAttributeRetPtr(unsigned int *index)){rlEnableVertexAttribute(*index);} // Enable vertex attribute index
DECLARE(void rlDisableVertexAttributeRetPtr(unsigned int *index)){rlDisableVertexAttribute(*index);} // Disable vertex attribute index
DECLARE(void rlActiveTextureSlotRetPtr(int *slot)){rlActiveTextureSlot(*slot);}               // Select and active a texture slot
DECLARE(void rlEnableTextureRetPtr(unsigned int *id)){rlEnableTexture(*id);}            // Enable texture
DECLARE(void rlDisableTextureRetPtr()){rlDisableTexture();}                      // Disable texture
DECLARE(void rlEnableTextureCubemapRetPtr(unsigned int *id)){rlEnableTextureCubemap(*id);}     // Enable texture cubemap
DECLARE(void rlDisableTextureCubemapRetPtr()){rlDisableTextureCubemap();}               // Disable texture cubemap
DECLARE(void rlTextureParametersRetPtr(unsigned int *id,  int *param,  int *value)){rlTextureParameters(*id, *param, *value);} // Set texture parameters (filter, wrap)
DECLARE(void rlCubemapParametersRetPtr(unsigned int *id,  int *param,  int *value)){rlCubemapParameters(*id, *param, *value);} // Set cubemap parameters (filter, wrap)
DECLARE(void rlEnableShaderRetPtr(unsigned int *id)){rlEnableShader(*id);}             // Enable shader program
DECLARE(void rlDisableShaderRetPtr()){rlDisableShader();}                       // Disable shader program
DECLARE(void rlEnableFramebufferRetPtr(unsigned int *id)){rlEnableFramebuffer(*id);}        // Enable render texture (fbo)
DECLARE(void rlDisableFramebufferRetPtr()){rlDisableFramebuffer();}                  // Disable render texture (fbo), return to default framebuffer
DECLARE(void rlGetActiveFramebufferRetPtr(unsigned int *ret)){*ret=rlGetActiveFramebuffer();}        // Get the currently active render texture (fbo), 0 for default framebuffer
DECLARE(void rlActiveDrawBuffersRetPtr(int *count)){rlActiveDrawBuffers(*count);}              // Activate multiple draw color buffers
DECLARE(void rlBlitFramebufferRetPtr(int *srcX,  int *srcY,  int *srcWidth,  int *srcHeight,  int *dstX,  int *dstY,  int *dstWidth,  int *dstHeight,  int *bufferMask)){rlBlitFramebuffer(*srcX, *srcY, *srcWidth, *srcHeight, *dstX, *dstY, *dstWidth, *dstHeight, *bufferMask);} // Blit active framebuffer to main framebuffer
DECLARE(void rlBindFramebufferRetPtr(unsigned int *target,  unsigned int *framebuffer)){rlBindFramebuffer(*target, *framebuffer);} // Bind framebuffer (FBO)
DECLARE(void rlEnableColorBlendRetPtr()){rlEnableColorBlend();}                    // Enable color blending
DECLARE(void rlDisableColorBlendRetPtr()){rlDisableColorBlend();}                   // Disable color blending
DECLARE(void rlEnableDepthTestRetPtr()){rlEnableDepthTest();}                     // Enable depth test
DECLARE(void rlDisableDepthTestRetPtr()){rlDisableDepthTest();}                    // Disable depth test
DECLARE(void rlEnableDepthMaskRetPtr()){rlEnableDepthMask();}                     // Enable depth write
DECLARE(void rlDisableDepthMaskRetPtr()){rlDisableDepthMask();}                    // Disable depth write
DECLARE(void rlEnableBackfaceCullingRetPtr()){rlEnableBackfaceCulling();}               // Enable backface culling
DECLARE(void rlDisableBackfaceCullingRetPtr()){rlDisableBackfaceCulling();}              // Disable backface culling
DECLARE(void rlColorMaskRetPtr(bool *r,  bool *g,  bool *b,  bool *a)){rlColorMask(*r, *g, *b, *a);} // Color mask control
DECLARE(void rlSetCullFaceRetPtr(int *mode)){rlSetCullFace(*mode);}                     // Set face culling mode
DECLARE(void rlEnableScissorTestRetPtr()){rlEnableScissorTest();}                   // Enable scissor test
DECLARE(void rlDisableScissorTestRetPtr()){rlDisableScissorTest();}                  // Disable scissor test
DECLARE(void rlScissorRetPtr(int *x,  int *y,  int *width,  int *height)){rlScissor(*x, *y, *width, *height);} // Scissor test
DECLARE(void rlEnableWireModeRetPtr()){rlEnableWireMode();}                      // Enable wire mode
DECLARE(void rlEnablePointModeRetPtr()){rlEnablePointMode();}                     // Enable point mode
DECLARE(void rlDisableWireModeRetPtr()){rlDisableWireMode();}                     // Disable wire (and point) mode
DECLARE(void rlSetLineWidthRetPtr(float *width)){rlSetLineWidth(*width);}                 // Set the line drawing width
DECLARE(void rlGetLineWidthRetPtr(float *ret)){*ret=rlGetLineWidth();}                       // Get the line drawing width
DECLARE(void rlEnableSmoothLinesRetPtr()){rlEnableSmoothLines();}                   // Enable line aliasing
DECLARE(void rlDisableSmoothLinesRetPtr()){rlDisableSmoothLines();}                  // Disable line aliasing
DECLARE(void rlEnableStereoRenderRetPtr()){rlEnableStereoRender();}                  // Enable stereo rendering
DECLARE(void rlDisableStereoRenderRetPtr()){rlDisableStereoRender();}                 // Disable stereo rendering
DECLARE(void rlIsStereoRenderEnabledRetPtr(bool *ret)){*ret=rlIsStereoRenderEnabled();}               // Check if stereo render is enabled
DECLARE(void rlClearColorRetPtr(unsigned char *r,  unsigned char *g,  unsigned char *b,  unsigned char *a)){rlClearColor(*r, *g, *b, *a);} // Clear color buffer with color
DECLARE(void rlClearScreenBuffersRetPtr()){rlClearScreenBuffers();}                  // Clear used screen buffers (color and depth)
DECLARE(void rlCheckErrorsRetPtr()){rlCheckErrors();}                         // Check and log OpenGL error codes
DECLARE(void rlSetBlendModeRetPtr(int *mode)){rlSetBlendMode(*mode);}                    // Set blending mode
DECLARE(void rlSetBlendFactorsRetPtr(int *glSrcFactor,  int *glDstFactor,  int *glEquation)){rlSetBlendFactors(*glSrcFactor, *glDstFactor, *glEquation);} // Set blending mode factor and equation (using OpenGL factors)
DECLARE(void rlSetBlendFactorsSeparateRetPtr(int *glSrcRGB,  int *glDstRGB,  int *glSrcAlpha,  int *glDstAlpha,  int *glEqRGB,  int *glEqAlpha)){rlSetBlendFactorsSeparate(*glSrcRGB, *glDstRGB, *glSrcAlpha, *glDstAlpha, *glEqRGB, *glEqAlpha);} // Set blending mode factors and equations separately (using OpenGL factors)
DECLARE(void rlglInitRetPtr(int *width,  int *height)){rlglInit(*width, *height);}             // Initialize rlgl (buffers, shaders, textures, states)
DECLARE(void rlglCloseRetPtr()){rlglClose();}                             // De-initialize rlgl (buffers, shaders, textures)
DECLARE(void rlLoadExtensionsRetPtr(void **loader)){rlLoadExtensions(*loader);}              // Load OpenGL extensions (loader function required)
DECLARE(void rlGetVersionRetPtr(int *ret)){*ret=rlGetVersion();}                           // Get current OpenGL version
DECLARE(void rlSetFramebufferWidthRetPtr(int *width)){rlSetFramebufferWidth(*width);}            // Set current framebuffer width
DECLARE(void rlGetFramebufferWidthRetPtr(int *ret)){*ret=rlGetFramebufferWidth();}                  // Get default framebuffer width
DECLARE(void rlSetFramebufferHeightRetPtr(int *height)){rlSetFramebufferHeight(*height);}          // Set current framebuffer height
DECLARE(void rlGetFramebufferHeightRetPtr(int *ret)){*ret=rlGetFramebufferHeight();}                 // Get default framebuffer height
DECLARE(void rlGetTextureIdDefaultRetPtr(unsigned int *ret)){*ret=rlGetTextureIdDefault();}         // Get default texture id
DECLARE(void rlGetShaderIdDefaultRetPtr(unsigned int *ret)){*ret=rlGetShaderIdDefault();}          // Get default shader id
DECLARE(void rlGetShaderLocsDefaultRetPtr(int **ret)){*ret=rlGetShaderLocsDefault();}                // Get default shader locations
DECLARE(void rlLoadRenderBatchRetPtr(rlRenderBatch *ret, int *numBuffers,  int *bufferElements)){*ret=rlLoadRenderBatch(*numBuffers, *bufferElements);} // Load a render batch system
DECLARE(void rlUnloadRenderBatchRetPtr(rlRenderBatch *batch)){rlUnloadRenderBatch(*batch);}    // Unload render batch system
DECLARE(void rlDrawRenderBatchRetPtr(rlRenderBatch **batch)){rlDrawRenderBatch(*batch);}     // Draw render batch data (Update->Draw->Reset)
DECLARE(void rlSetRenderBatchActiveRetPtr(rlRenderBatch **batch)){rlSetRenderBatchActive(*batch);} // Set the active render batch for rlgl (NULL for default internal)
DECLARE(void rlDrawRenderBatchActiveRetPtr()){rlDrawRenderBatchActive();}               // Update and draw internal render batch
DECLARE(void rlCheckRenderBatchLimitRetPtr(bool *ret, int *vCount)){*ret=rlCheckRenderBatchLimit(*vCount);}         // Check internal buffer overflow for a given number of vertex
DECLARE(void rlSetTextureRetPtr(unsigned int *id)){rlSetTexture(*id);}               // Set current texture for render batch and check buffers limits
DECLARE(void rlLoadVertexArrayRetPtr(unsigned int *ret)){*ret=rlLoadVertexArray();}             // Load vertex array (vao) if supported
DECLARE(void rlLoadVertexBufferRetPtr(unsigned int *ret, const void **buffer,  int *size,  bool *dynamic)){*ret=rlLoadVertexBuffer(*buffer, *size, *dynamic);} // Load a vertex buffer object
DECLARE(void rlLoadVertexBufferElementRetPtr(unsigned int *ret, const void **buffer,  int *size,  bool *dynamic)){*ret=rlLoadVertexBufferElement(*buffer, *size, *dynamic);} // Load vertex buffer elements object
DECLARE(void rlUpdateVertexBufferRetPtr(unsigned int *bufferId,  const void **data,  int *dataSize,  int *offset)){rlUpdateVertexBuffer(*bufferId, *data, *dataSize, *offset);} // Update vertex buffer object data on GPU buffer
DECLARE(void rlUpdateVertexBufferElementsRetPtr(unsigned int *id,  const void **data,  int *dataSize,  int *offset)){rlUpdateVertexBufferElements(*id, *data, *dataSize, *offset);} // Update vertex buffer elements data on GPU buffer
DECLARE(void rlUnloadVertexArrayRetPtr(unsigned int *vaoId)){rlUnloadVertexArray(*vaoId);}     // Unload vertex array (vao)
DECLARE(void rlUnloadVertexBufferRetPtr(unsigned int *vboId)){rlUnloadVertexBuffer(*vboId);}    // Unload vertex buffer object
DECLARE(void rlSetVertexAttributeRetPtr(unsigned int *index,  int *compSize,  int *type,  bool *normalized,  int *stride,  int *offset)){rlSetVertexAttribute(*index, *compSize, *type, *normalized, *stride, *offset);} // Set vertex attribute data configuration
DECLARE(void rlSetVertexAttributeDivisorRetPtr(unsigned int *index,  int *divisor)){rlSetVertexAttributeDivisor(*index, *divisor);} // Set vertex attribute data divisor
DECLARE(void rlSetVertexAttributeDefaultRetPtr(int *locIndex,  const void **value,  int *attribType,  int *count)){rlSetVertexAttributeDefault(*locIndex, *value, *attribType, *count);} // Set vertex attribute default value, when attribute to provided
DECLARE(void rlDrawVertexArrayRetPtr(int *offset,  int *count)){rlDrawVertexArray(*offset, *count);}    // Draw vertex array (currently active vao)
DECLARE(void rlDrawVertexArrayElementsRetPtr(int *offset,  int *count,  const void **buffer)){rlDrawVertexArrayElements(*offset, *count, *buffer);} // Draw vertex array elements
DECLARE(void rlDrawVertexArrayInstancedRetPtr(int *offset,  int *count,  int *instances)){rlDrawVertexArrayInstanced(*offset, *count, *instances);} // Draw vertex array (currently active vao) with instancing
DECLARE(void rlDrawVertexArrayElementsInstancedRetPtr(int *offset,  int *count,  const void **buffer,  int *instances)){rlDrawVertexArrayElementsInstanced(*offset, *count, *buffer, *instances);} // Draw vertex array elements with instancing
DECLARE(void rlLoadTextureRetPtr(unsigned int *ret, const void **data,  int *width,  int *height,  int *format,  int *mipmapCount)){*ret=rlLoadTexture(*data, *width, *height, *format, *mipmapCount);} // Load texture data
DECLARE(void rlLoadTextureDepthRetPtr(unsigned int *ret, int *width,  int *height,  bool *useRenderBuffer)){*ret=rlLoadTextureDepth(*width, *height, *useRenderBuffer);} // Load depth texture/renderbuffer (to be attached to fbo)
DECLARE(void rlLoadTextureCubemapRetPtr(unsigned int *ret, const void **data,  int *size,  int *format,  int *mipmapCount)){*ret=rlLoadTextureCubemap(*data, *size, *format, *mipmapCount);} // Load texture cubemap data
DECLARE(void rlUpdateTextureRetPtr(unsigned int *id,  int *offsetX,  int *offsetY,  int *width,  int *height,  int *format,  const void **data)){rlUpdateTexture(*id, *offsetX, *offsetY, *width, *height, *format, *data);} // Update texture with new data on GPU
DECLARE(void rlGetGlTextureFormatsRetPtr(int *format,  unsigned int **glInternalFormat,  unsigned int **glFormat,  unsigned int **glType)){rlGetGlTextureFormats(*format, *glInternalFormat, *glFormat, *glType);} // Get OpenGL internal formats
DECLARE(void rlGetPixelFormatNameRetPtr(const char **ret, unsigned int *format)){*ret=rlGetPixelFormatName(*format);}              // Get name string for pixel format
DECLARE(void rlUnloadTextureRetPtr(unsigned int *id)){rlUnloadTexture(*id);}                              // Unload texture from GPU memory
DECLARE(void rlGenTextureMipmapsRetPtr(unsigned int *id,  int *width,  int *height,  int *format,  int **mipmaps)){rlGenTextureMipmaps(*id, *width, *height, *format, *mipmaps);} // Generate mipmap data for selected texture
DECLARE(void rlReadTexturePixelsRetPtr(void **ret, unsigned int *id,  int *width,  int *height,  int *format)){*ret=rlReadTexturePixels(*id, *width, *height, *format);} // Read texture pixel data
DECLARE(void rlReadScreenPixelsRetPtr(unsigned char **ret, int *width,  int *height)){*ret=rlReadScreenPixels(*width, *height);}           // Read screen pixel data (color buffer)
DECLARE(void rlLoadFramebufferRetPtr(unsigned int *ret)){*ret=rlLoadFramebuffer();}                               // Load an empty framebuffer
DECLARE(void rlFramebufferAttachRetPtr(unsigned int *fboId,  unsigned int *texId,  int *attachType,  int *texType,  int *mipLevel)){rlFramebufferAttach(*fboId, *texId, *attachType, *texType, *mipLevel);} // Attach texture/renderbuffer to a framebuffer
DECLARE(void rlFramebufferCompleteRetPtr(bool *ret, unsigned int *id)){*ret=rlFramebufferComplete(*id);}                        // Verify framebuffer is complete
DECLARE(void rlUnloadFramebufferRetPtr(unsigned int *id)){rlUnloadFramebuffer(*id);}                          // Delete framebuffer from GPU
DECLARE(void rlLoadShaderCodeRetPtr(unsigned int *ret, const char **vsCode,  const char **fsCode)){*ret=rlLoadShaderCode(*vsCode, *fsCode);}    // Load shader from code strings
DECLARE(void rlCompileShaderRetPtr(unsigned int *ret, const char **shaderCode,  int *type)){*ret=rlCompileShader(*shaderCode, *type);}           // Compile custom shader and return shader id (type: RL_VERTEX_SHADER, RL_FRAGMENT_SHADER, RL_COMPUTE_SHADER)
DECLARE(void rlLoadShaderProgramRetPtr(unsigned int *ret, unsigned int *vShaderId,  unsigned int *fShaderId)){*ret=rlLoadShaderProgram(*vShaderId, *fShaderId);} // Load custom shader program
DECLARE(void rlUnloadShaderProgramRetPtr(unsigned int *id)){rlUnloadShaderProgram(*id);}                              // Unload shader program
DECLARE(void rlGetLocationUniformRetPtr(int *ret, unsigned int *shaderId,  const char **uniformName)){*ret=rlGetLocationUniform(*shaderId, *uniformName);} // Get shader location uniform
DECLARE(void rlGetLocationAttribRetPtr(int *ret, unsigned int *shaderId,  const char **attribName)){*ret=rlGetLocationAttrib(*shaderId, *attribName);}   // Get shader location attribute
DECLARE(void rlSetUniformRetPtr(int *locIndex,  const void **value,  int *uniformType,  int *count)){rlSetUniform(*locIndex, *value, *uniformType, *count);} // Set shader value uniform
DECLARE(void rlSetUniformMatrixRetPtr(int *locIndex,  Matrix *mat)){rlSetUniformMatrix(*locIndex, *mat);}                        // Set shader value matrix
DECLARE(void rlSetUniformMatricesRetPtr(int *locIndex,  const Matrix **mat,  int *count)){rlSetUniformMatrices(*locIndex, *mat, *count);}    // Set shader value matrices
DECLARE(void rlSetUniformSamplerRetPtr(int *locIndex,  unsigned int *textureId)){rlSetUniformSampler(*locIndex, *textureId);}           // Set shader value sampler
DECLARE(void rlSetShaderRetPtr(unsigned int *id,  int **locs)){rlSetShader(*id, *locs);}                             // Set shader currently active (id and locations)
DECLARE(void rlLoadComputeShaderProgramRetPtr(unsigned int *ret, unsigned int *shaderId)){*ret=rlLoadComputeShaderProgram(*shaderId);}           // Load compute shader program
DECLARE(void rlComputeShaderDispatchRetPtr(unsigned int *groupX,  unsigned int *groupY,  unsigned int *groupZ)){rlComputeShaderDispatch(*groupX, *groupY, *groupZ);} // Dispatch compute shader (equivalent to *draw* for graphics pipeline)
DECLARE(void rlLoadShaderBufferRetPtr(unsigned int *ret, unsigned int *size,  const void **data,  int *usageHint)){*ret=rlLoadShaderBuffer(*size, *data, *usageHint);} // Load shader storage buffer object (SSBO)
DECLARE(void rlUnloadShaderBufferRetPtr(unsigned int *ssboId)){rlUnloadShaderBuffer(*ssboId);}                           // Unload shader storage buffer object (SSBO)
DECLARE(void rlUpdateShaderBufferRetPtr(unsigned int *id,  const void **data,  unsigned int *dataSize,  unsigned int *offset)){rlUpdateShaderBuffer(*id, *data, *dataSize, *offset);} // Update SSBO buffer data
DECLARE(void rlBindShaderBufferRetPtr(unsigned int *id,  unsigned int *index)){rlBindShaderBuffer(*id, *index);}             // Bind SSBO buffer
DECLARE(void rlReadShaderBufferRetPtr(unsigned int *id,  void **dest,  unsigned int *count,  unsigned int *offset)){rlReadShaderBuffer(*id, *dest, *count, *offset);} // Read SSBO buffer data (GPU->CPU)
DECLARE(void rlCopyShaderBufferRetPtr(unsigned int *destId,  unsigned int *srcId,  unsigned int *destOffset,  unsigned int *srcOffset,  unsigned int *count)){rlCopyShaderBuffer(*destId, *srcId, *destOffset, *srcOffset, *count);} // Copy SSBO data between buffers
DECLARE(void rlGetShaderBufferSizeRetPtr(unsigned int *ret, unsigned int *id)){*ret=rlGetShaderBufferSize(*id);}                      // Get SSBO buffer size
DECLARE(void rlBindImageTextureRetPtr(unsigned int *id,  unsigned int *index,  int *format,  bool *readonly)){rlBindImageTexture(*id, *index, *format, *readonly);}  // Bind image texture
DECLARE(void rlGetMatrixModelviewRetPtr(Matrix *ret)){*ret=rlGetMatrixModelview();}                                  // Get internal modelview matrix
DECLARE(void rlGetMatrixProjectionRetPtr(Matrix *ret)){*ret=rlGetMatrixProjection();}                                 // Get internal projection matrix
DECLARE(void rlGetMatrixTransformRetPtr(Matrix *ret)){*ret=rlGetMatrixTransform();}                                  // Get internal accumulated transform matrix
DECLARE(void rlGetMatrixProjectionStereoRetPtr(Matrix *ret, int *eye)){*ret=rlGetMatrixProjectionStereo(*eye);}                        // Get internal projection matrix for stereo render (selected eye)
DECLARE(void rlGetMatrixViewOffsetStereoRetPtr(Matrix *ret, int *eye)){*ret=rlGetMatrixViewOffsetStereo(*eye);}                        // Get internal view offset matrix for stereo render (selected eye)
DECLARE(void rlSetMatrixProjectionRetPtr(Matrix *proj)){rlSetMatrixProjection(*proj);}                            // Set a custom projection matrix (replaces internal projection matrix)
DECLARE(void rlSetMatrixModelviewRetPtr(Matrix *view)){rlSetMatrixModelview(*view);}                             // Set a custom modelview matrix (replaces internal modelview matrix)
DECLARE(void rlSetMatrixProjectionStereoRetPtr(Matrix *right,  Matrix *left)){rlSetMatrixProjectionStereo(*right, *left);}        // Set eyes projection matrices for stereo rendering
DECLARE(void rlSetMatrixViewOffsetStereoRetPtr(Matrix *right,  Matrix *left)){rlSetMatrixViewOffsetStereo(*right, *left);}        // Set eyes view offsets matrices for stereo rendering
DECLARE(void rlLoadDrawCubeRetPtr()){rlLoadDrawCube();}     // Load and draw a cube
DECLARE(void rlLoadDrawQuadRetPtr()){rlLoadDrawQuad();}     // Load and draw a quad
DECLARE(void GuiEnableRetPtr()){GuiEnable();}                                 // Enable gui controls (global state)
DECLARE(void GuiDisableRetPtr()){GuiDisable();}                                // Disable gui controls (global state)
DECLARE(void GuiLockRetPtr()){GuiLock();}                                   // Lock gui controls (global state)
DECLARE(void GuiUnlockRetPtr()){GuiUnlock();}                                 // Unlock gui controls (global state)
DECLARE(void GuiIsLockedRetPtr(bool *ret)){*ret=GuiIsLocked();}                               // Check if gui is locked (global state)
DECLARE(void GuiSetAlphaRetPtr(float *alpha)){GuiSetAlpha(*alpha);}                        // Set gui controls alpha (global state), alpha goes from 0.0f to 1.0f
DECLARE(void GuiSetStateRetPtr(int *state)){GuiSetState(*state);}                          // Set gui state (global state)
DECLARE(void GuiGetStateRetPtr(int *ret)){*ret=GuiGetState();}                                // Get gui state (global state)
DECLARE(void GuiSetFontRetPtr(Font *font)){GuiSetFont(*font);}                           // Set gui custom font (global state)
DECLARE(void GuiGetFontRetPtr(Font *ret)){*ret=GuiGetFont();}                                // Get gui custom font (global state)
DECLARE(void GuiSetStyleRetPtr(int *control,  int *property,  int *value)){GuiSetStyle(*control, *property, *value);} // Set one style property
DECLARE(void GuiGetStyleRetPtr(int *ret, int *control,  int *property)){*ret=GuiGetStyle(*control, *property);}           // Get one style property
DECLARE(void GuiLoadStyleRetPtr(const char **fileName)){GuiLoadStyle(*fileName);}              // Load style file over global style variable (.rgs)
DECLARE(void GuiLoadStyleDefaultRetPtr()){GuiLoadStyleDefault();}                       // Load style default over global style
DECLARE(void GuiEnableTooltipRetPtr()){GuiEnableTooltip();}                          // Enable gui tooltips (global state)
DECLARE(void GuiDisableTooltipRetPtr()){GuiDisableTooltip();}                         // Disable gui tooltips (global state)
DECLARE(void GuiSetTooltipRetPtr(const char **tooltip)){GuiSetTooltip(*tooltip);}              // Set tooltip string
DECLARE(void GuiIconTextRetPtr(const char **ret, int *iconId,  const char **text)){*ret=GuiIconText(*iconId, *text);} // Get text with icon id prepended (if supported)
DECLARE(void GuiSetIconScaleRetPtr(int *scale)){GuiSetIconScale(*scale);}                      // Set default icon drawing size
DECLARE(void GuiGetIconsRetPtr(unsigned int **ret)){*ret=GuiGetIcons();}                      // Get raygui icons data pointer
DECLARE(void GuiLoadIconsRetPtr(char ***ret, const char **fileName,  bool *loadIconsName)){*ret=GuiLoadIcons(*fileName, *loadIconsName);} // Load raygui icons file (.rgi) into internal icons data
DECLARE(void GuiDrawIconRetPtr(int *iconId,  int *posX,  int *posY,  int *pixelSize,  Color *color)){GuiDrawIcon(*iconId, *posX, *posY, *pixelSize, *color);} // Draw icon using pixel size at specified position
DECLARE(void GuiWindowBoxRetPtr(int *ret, Rectangle *bounds,  const char **title)){*ret=GuiWindowBox(*bounds, *title);}                                       // Window Box control, shows a window that can be closed
DECLARE(void GuiGroupBoxRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiGroupBox(*bounds, *text);}                                         // Group Box control with text name
DECLARE(void GuiLineRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiLine(*bounds, *text);}                                             // Line separator control, could contain text
DECLARE(void GuiPanelRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiPanel(*bounds, *text);}                                            // Panel control, useful to group controls
DECLARE(void GuiTabBarRetPtr(int *ret, Rectangle *bounds,  const char ***text,  int *count,  int **active)){*ret=GuiTabBar(*bounds, *text, *count, *active);}                  // Tab Bar control, returns TAB to be closed or -1
DECLARE(void GuiScrollPanelRetPtr(int *ret, Rectangle *bounds,  const char **text,  Rectangle *content,  Vector2 **scroll,  Rectangle **view)){*ret=GuiScrollPanel(*bounds, *text, *content, *scroll, *view);} // Scroll Panel control
DECLARE(void GuiLabelRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiLabel(*bounds, *text);}                                            // Label control, shows text
DECLARE(void GuiButtonRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiButton(*bounds, *text);}                                           // Button control, returns true when clicked
DECLARE(void GuiLabelButtonRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiLabelButton(*bounds, *text);}                                      // Label button control, show true when clicked
DECLARE(void GuiToggleRetPtr(int *ret, Rectangle *bounds,  const char **text,  bool **active)){*ret=GuiToggle(*bounds, *text, *active);}                             // Toggle Button control, returns true when active
DECLARE(void GuiToggleGroupRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **active)){*ret=GuiToggleGroup(*bounds, *text, *active);}                         // Toggle Group control, returns active toggle index
DECLARE(void GuiToggleSliderRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **active)){*ret=GuiToggleSlider(*bounds, *text, *active);}                        // Toggle Slider control, returns true when clicked
DECLARE(void GuiCheckBoxRetPtr(int *ret, Rectangle *bounds,  const char **text,  bool **checked)){*ret=GuiCheckBox(*bounds, *text, *checked);}                          // Check Box control, returns true when active
DECLARE(void GuiComboBoxRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **active)){*ret=GuiComboBox(*bounds, *text, *active);}                            // Combo Box control, returns selected item index
DECLARE(void GuiDropdownBoxRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **active,  bool *editMode)){*ret=GuiDropdownBox(*bounds, *text, *active, *editMode);}          // Dropdown Box control, returns selected item
DECLARE(void GuiSpinnerRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **value,  int *minValue,  int *maxValue,  bool *editMode)){*ret=GuiSpinner(*bounds, *text, *value, *minValue, *maxValue, *editMode);} // Spinner control, returns selected value
DECLARE(void GuiValueBoxRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **value,  int *minValue,  int *maxValue,  bool *editMode)){*ret=GuiValueBox(*bounds, *text, *value, *minValue, *maxValue, *editMode);} // Value Box control, updates input text with numbers
DECLARE(void GuiTextBoxRetPtr(int *ret, Rectangle *bounds,  char **text,  int *textSize,  bool *editMode)){*ret=GuiTextBox(*bounds, *text, *textSize, *editMode);}                   // Text Box control, updates input text
DECLARE(void GuiSliderRetPtr(int *ret, Rectangle *bounds,  const char **textLeft,  const char **textRight,  float **value,  float *minValue,  float *maxValue)){*ret=GuiSlider(*bounds, *textLeft, *textRight, *value, *minValue, *maxValue);} // Slider control, returns selected value
DECLARE(void GuiSliderBarRetPtr(int *ret, Rectangle *bounds,  const char **textLeft,  const char **textRight,  float **value,  float *minValue,  float *maxValue)){*ret=GuiSliderBar(*bounds, *textLeft, *textRight, *value, *minValue, *maxValue);} // Slider Bar control, returns selected value
DECLARE(void GuiProgressBarRetPtr(int *ret, Rectangle *bounds,  const char **textLeft,  const char **textRight,  float **value,  float *minValue,  float *maxValue)){*ret=GuiProgressBar(*bounds, *textLeft, *textRight, *value, *minValue, *maxValue);} // Progress Bar control, shows current progress value
DECLARE(void GuiStatusBarRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiStatusBar(*bounds, *text);}                                        // Status Bar control, shows info text
DECLARE(void GuiDummyRecRetPtr(int *ret, Rectangle *bounds,  const char **text)){*ret=GuiDummyRec(*bounds, *text);}                                         // Dummy control for placeholders
DECLARE(void GuiGridRetPtr(int *ret, Rectangle *bounds,  const char **text,  float *spacing,  int *subdivs,  Vector2 **mouseCell)){*ret=GuiGrid(*bounds, *text, *spacing, *subdivs, *mouseCell);} // Grid control, returns mouse cell position
DECLARE(void GuiListViewRetPtr(int *ret, Rectangle *bounds,  const char **text,  int **scrollIndex,  int **active)){*ret=GuiListView(*bounds, *text, *scrollIndex, *active);}          // List View control, returns selected list item index
DECLARE(void GuiListViewExRetPtr(int *ret, Rectangle *bounds,  const char ***text,  int *count,  int **scrollIndex,  int **active,  int **focus)){*ret=GuiListViewEx(*bounds, *text, *count, *scrollIndex, *active, *focus);} // List View with extended parameters
DECLARE(void GuiMessageBoxRetPtr(int *ret, Rectangle *bounds,  const char **title,  const char **message,  const char **buttons)){*ret=GuiMessageBox(*bounds, *title, *message, *buttons);} // Message Box control, displays a message
DECLARE(void GuiTextInputBoxRetPtr(int *ret, Rectangle *bounds,  const char **title,  const char **message,  const char **buttons,  char **text,  int *textMaxSize,  bool **secretViewActive)){*ret=GuiTextInputBox(*bounds, *title, *message, *buttons, *text, *textMaxSize, *secretViewActive);} // Text Input Box control, ask for text, supports secret
DECLARE(void GuiColorPickerRetPtr(int *ret, Rectangle *bounds,  const char **text,  Color **color)){*ret=GuiColorPicker(*bounds, *text, *color);}                        // Color Picker control (multiple color controls)
DECLARE(void GuiColorPanelRetPtr(int *ret, Rectangle *bounds,  const char **text,  Color **color)){*ret=GuiColorPanel(*bounds, *text, *color);}                         // Color Panel control
DECLARE(void GuiColorBarAlphaRetPtr(int *ret, Rectangle *bounds,  const char **text,  float **alpha)){*ret=GuiColorBarAlpha(*bounds, *text, *alpha);}                      // Color Bar Alpha control
DECLARE(void GuiColorBarHueRetPtr(int *ret, Rectangle *bounds,  const char **text,  float **value)){*ret=GuiColorBarHue(*bounds, *text, *value);}                        // Color Bar Hue control
DECLARE(void GuiColorPickerHSVRetPtr(int *ret, Rectangle *bounds,  const char **text,  Vector3 **colorHsv)){*ret=GuiColorPickerHSV(*bounds, *text, *colorHsv);}                // Color Picker control that avoids conversion to RGB on each call (multiple color controls)
DECLARE(void GuiColorPanelHSVRetPtr(int *ret, Rectangle *bounds,  const char **text,  Vector3 **colorHsv)){*ret=GuiColorPanelHSV(*bounds, *text, *colorHsv);}                 // Color Panel control that returns HSV color value, used by GuiColorPickerHSV()
