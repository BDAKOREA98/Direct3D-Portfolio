cbuffer World : register(b0)
{
    matrix world;
};

cbuffer View : register(b1)
{
    matrix view;
    matrix invView;
};

cbuffer Proj : register(b2)
{
    matrix proj;
};

cbuffer LightDirection : register(b0)
{
    float3 lightDirection;
    float padding;
    float4 ambientLight;
};

cbuffer MaterialBuffer : register(b1)
{
    float4 mDiffuse;
    float4 mSpecular;
    float4 mAmbient;
    
    int hasDiffuseMap;
    int hasSpecularMap;
    int hasNormalMap;
    
    float shininess;
}

struct VertexColor
{
    float4 pos : POSITION;
    float4 color : COLOR;
};

struct VertexTexture
{
    float4 pos : POSITION;
    float2 uv : UV;
};

struct VertexTextureNormal
{
    float4 pos : POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
};

struct VertexColorNormal
{
    float4 pos : POSITION;
    float4 color : COLOR;
    float3 normal : NORMAL;
};

struct VertexTextureNormalTangent
{
    float4 pos : POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
};

Texture2D diffuseMap : register(t0);
Texture2D specularMap : register(t1);
Texture2D normalMap : register(t2);

SamplerState samp : register(s0);