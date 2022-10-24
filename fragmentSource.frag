#version 330 core
in vec4 vertexColor;
//uniform vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourFace;

uniform vec3 objColor;
uniform vec3 ambientColor;


out vec4 FragColor;
void main()
{
    //FragColor = vertexColor;
    //FragColor = texture(ourTexture, TexCoord)*texture(ourFace, TexCoord);
    //FragColor = mix(texture(ourTexture, TexCoord), texture(ourFace, TexCoord), 0.2);
    FragColor= vec4 ( objColor * ambientColor , 1.0f )*texture(ourFace, TexCoord);

}