#include "Header.hlsli"

struct VertexOutput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float3 binormal : BINORMAL;
    float3 viewDir : VIEWDIR;
};

VertexOutput main(VertexTextureNormalTangent input)
{
    VertexOutput output;
    
    output.pos = mul(input.pos, world);
    
    float3 cameraPos = invView._41_42_43;
    
    output.viewDir = normalize(output.pos.xyz - cameraPos);
    
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, proj);
    
    output.uv = input.uv;
                    
    output.normal = normalize(mul(input.normal, (float3x3) world));
    output.tangent = normalize(mul(input.tangent, (float3x3) world));
    
    output.binormal = cross(output.normal, output.tangent);
    
    return output;
}