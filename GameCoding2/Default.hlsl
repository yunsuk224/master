
struct VS_INPUT
{
    float4 position : POSITION; //GPU가 정점의 위치 데이터를 이 변수로 인식한다. 이말임.
    //float4 color : COLOR;
    float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;  //GPU가 셰이더를 통과하며 바뀐 위치를 SV_POSITION 변수명을 갖는다 이말인가?
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