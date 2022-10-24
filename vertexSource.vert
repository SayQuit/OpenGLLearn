#version 330 core
layout (location = 6) in vec3 aPos;
layout (location = 7) in vec3 aColor;
layout (location = 8) in vec2 aTexCoord;

uniform mat4 transform;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

out vec4 vertexColor;
out vec2 TexCoord;
void main()
{
   gl_Position =  projMat * viewMat * modelMat * transform *vec4(aPos.x, aPos.y, aPos.z, 1.0);
   vertexColor = vec4(aColor.x,aColor.y,aColor.z,1.0);
   TexCoord=aTexCoord;
}