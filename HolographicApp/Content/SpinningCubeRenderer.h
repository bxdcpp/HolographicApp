#pragma once

#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"
#include "ShaderStructures.h"

namespace HolographicApp
{
    // This sample renderer instantiates a basic rendering pipeline.
    class SpinningCubeRenderer
    {
    public:
        SpinningCubeRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
        void CreateDeviceDependentResources();
        void ReleaseDeviceDependentResources();
        void Update(const DX::StepTimer& timer);
        void Render();
		void SetTexture2D();
		std::wstring stows(std::string s);
		Platform::String^ stops(std::string s);
		std::string wstos(std::wstring ws);
		std::string pstos(Platform::String^ ps);
		

        // Repositions the sample hologram.
        void PositionHologram(Windows::UI::Input::Spatial::SpatialPointerPose^ pointerPose);

        // Property accessors.
        void SetPosition(Windows::Foundation::Numerics::float3 pos) { m_position = pos;  }
        Windows::Foundation::Numerics::float3 GetPosition()         { return m_position; }

    private:
        // Cached pointer to device resources.
        std::shared_ptr<DX::DeviceResources>            m_deviceResources;

        // Direct3D resources for cube geometry.
        Microsoft::WRL::ComPtr<ID3D11InputLayout>       m_inputLayout;
        Microsoft::WRL::ComPtr<ID3D11Buffer>            m_vertexBuffer;
        Microsoft::WRL::ComPtr<ID3D11Buffer>            m_indexBuffer;
        Microsoft::WRL::ComPtr<ID3D11VertexShader>      m_vertexShader;
        Microsoft::WRL::ComPtr<ID3D11GeometryShader>    m_geometryShader;
        Microsoft::WRL::ComPtr<ID3D11PixelShader>       m_pixelShader;
        Microsoft::WRL::ComPtr<ID3D11Buffer>            m_modelConstantBuffer;

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>        m_shaderResourceView;
		Microsoft::WRL::ComPtr<ID3D11Resource>          m_resource;
		//Microsoft::WRL::ComPtr<ID3D11Texture2D>         m_pTextureRV;
		Microsoft::WRL::ComPtr<ID3D11SamplerState>      m_samplerLinear;

        // System resources for cube geometry.
        ModelConstantBuffer                             m_modelConstantBufferData;
        uint32                                          m_indexCount = 0;

        // Variables used with the rendering loop.
        bool                                            m_loadingComplete = false;
        float                                           m_degreesPerSecond = 45.f;
        Windows::Foundation::Numerics::float3           m_position = { 0.f, 0.f, -2.f };

        // If the current D3D Device supports VPRT, we can avoid using a geometry
        // shader just to set the render target array index.
        bool                                            m_usingVprtShaders = false;
    };
}
