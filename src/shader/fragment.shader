#version 330 core 
out vec4 FragColor;

uniform vec3 lightSource;
uniform vec3 lightColor;
uniform vec3 objectColor;

in vec3 Normal;
in vec3 FragPos;

void main()
{
    //Calc ambient Lighting
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
    //Clac diffuse Lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(FragPos-lightSource);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    //Combine the two
    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}