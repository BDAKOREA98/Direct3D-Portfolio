#include "Header.hlsli"

struct VertexOutput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
};

float4 main(VertexOutput input) : SV_TARGET
{
    float3 L = normalize(-lightDirection);
    float diffuse = dot(input.normal, L); //N dot L
    
    
    return diffuseMap.Sample(samp, input.uv) * diffuse;
}