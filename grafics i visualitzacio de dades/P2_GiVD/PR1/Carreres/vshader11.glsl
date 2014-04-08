#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif


IN vec4 vPosition;
IN vec4 vColor;

OUT vec4 color;
uniform mat4 model_view;
uniform mat4 projection;

void main() 
{
  gl_Position = model_view*vPosition;
  gl_Position = projection*gl_Position;
  color = vColor;
} 
