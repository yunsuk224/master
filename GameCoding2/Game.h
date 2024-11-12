#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	// Draw
	void RenderBegin();
	void RenderEnd();

private:
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();
	void SetViewPort();

private:
	// 삼각형 그리기
	void CreateGeometry();
	void CreateInputLayout();

	// 셰이더
	void CreateVS();
	void CreatePS();
	void CreateSRV();

	// RS
	void CreateRasterizerState();

	// PS
	void CreateSamplerState();
	void CreateBlendState();

	// ConstantBuffer
	void CreateConstantBuffer();


	void LoadShaderFromFile(const wstring & path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);

private:
	HWND _hWnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// Device & SwapChain
	ComPtr<ID3D11Device> _device = nullptr;					// 리소스 생성
	ComPtr<ID3D11DeviceContext> _deviceContext = nullptr;	// 생성된 리소스를 파이프라인에 연결시켜주는 명령
	ComPtr<IDXGISwapChain> _swapChain = nullptr;

	// RTV(RenderTargetView)
	ComPtr<ID3D11RenderTargetView> _renderTargetView;	

	// Misc
	D3D11_VIEWPORT _viewport = { 0 };
	float _clearColor[4] = { 0.f, 0.f, 0.f, 0.f };

private:
	// Geometry
	vector<Vertex> _vertices;
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	vector<uint32> _indices;
	ComPtr<ID3D11Buffer> _indexBuffer = nullptr;
	ComPtr<ID3D11InputLayout> _inputLayout = nullptr;
	ComPtr<ID3D11Buffer> _constantBuffer = nullptr;
	TransformData _transformData;

	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;

	// RS
	ComPtr<ID3D11RasterizerState> _rasterizerState = nullptr;
	ComPtr<ID3D11SamplerState> _samplerState = nullptr;
	ComPtr<ID3D11BlendState> _blendState = nullptr;

	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _psBlob = nullptr;

	// SRV
	ComPtr<ID3D11ShaderResourceView> _shaderResourceView = nullptr;

};

