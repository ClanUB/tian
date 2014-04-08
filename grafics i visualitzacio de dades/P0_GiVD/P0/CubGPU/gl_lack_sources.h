#ifndef GL_LACK_SOURCES_H
#define GL_LACK_SOURCES_H

#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBindVertexArray (GLuint array);
GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
GLAPI GLboolean APIENTRY glIsVertexArray (GLuint array);
#endif /* GL_GLEXT_PROTOTYPES */
#endif

#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
GLAPI GLboolean APIENTRY glIsQuery (GLuint id);
GLAPI void APIENTRY glBeginQuery (GLenum target, GLuint id);
GLAPI void APIENTRY glEndQuery (GLenum target);
GLAPI void APIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
GLAPI GLvoid* APIENTRY glMapBuffer (GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);
GLAPI void APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetBufferPointerv (GLenum target, GLenum pname, GLvoid* *params);
#endif /* GL_GLEXT_PROTOTYPES */

#endif // GL_LACK_SOURCES_H
