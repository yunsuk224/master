
struct VS_INPUT
{
    float4 position : POSITION; //GPU�� ������ ��ġ �����͸� �� ������ �ν��Ѵ�. �̸���.
    //float4 color : COLOR;
    float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;  //GPU�� ���̴��� ����ϸ� �ٲ� ��ġ�� SV_POSITION �������� ���´� �̸��ΰ�?
    //float4 color : COLOR;
    float2 uv : TEXCOORD;
};

cbuffer TransformData : register(b0)
{
    float4 offset;
}

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    
    output.position = input.position + offset;
    //output.color = input.color;
    output.uv = input.uv;
    
    return output;
}

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);


float4 PS(VS_OUTPUT input) : SV_Target
{
    float4 color = texture0.Sample(sampler0, input.uv);
    
    return color;
}