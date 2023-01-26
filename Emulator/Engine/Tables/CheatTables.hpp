#pragma once



/* Client table ( ref: https://api.nixware.cc/client/ ) */
namespace Client
{

	inline void LoadScript(std::string sScriptName)
	{
		g_EmulatorEngine.WriteTrace("Client::LoadScript ( " + sScriptName + " )");
	}

	inline void UnloadScript(std::string sScriptName)
	{
		g_EmulatorEngine.WriteTrace("Client::UnloadScript ( " + sScriptName + " )");
	}

	inline std::string GetScriptName()
	{
		g_EmulatorEngine.WriteTrace("Client::GetScriptName");

		return "scriptemu.lua";
	}

	inline void RegisterCallBack(std::string sName, sol::function fCallback)
	{
		g_EmulatorEngine.WriteTrace("Client::RegisterCallBack ( " + sName + " )");
		return g_CallBacksSystem.RegisterCallBack(sName, fCallback);
	}

	inline std::string GetUsername()
	{
		g_EmulatorEngine.WriteTrace("Client::GetUsername");

		return "sapdragon";
	}

	inline void Notify(std::string sMessage)
	{
		g_EmulatorEngine.WriteTrace("Client::Notify ( " + sMessage + " )");
	}
	
	inline int GetTimeStamp()
	{
		g_EmulatorEngine.WriteTrace("Client::GetTimeStamp");

		return 0xDEADFEED;
	}

	inline std::tuple < int, int, int> GetSystemTime()
	{
		g_EmulatorEngine.WriteTrace("Client::GetSystemTime");

		return std::make_tuple(0, 1, 2);
	}

	inline int FindPattern(std::string sModule, std::string sPattern)
	{
		g_EmulatorEngine.WriteTrace("Client::FindPattern ( " + sModule + " , " + sPattern + " )");

		return 0xC001C0DE;
	}

	
}

/* Render table ( ref: https://api.nixware.cc/renderer/ ) */
namespace Render
{
	struct Font_t
	{
		/* Path to font */
		std::string m_sPath;
		/* Font size */
		int m_iSize;
		/* Font flags */
		int m_iFlags;
	};
	
	struct Texture_t
	{
		/* Path to texture file */
		std::string m_sPath;
	};

	inline Font_t SetupFont(std::string sPath, int iSize, int iFlags)
	{
		g_EmulatorEngine.WriteTrace("Render::SetupFont ( " + sPath + " , " + std::to_string(iSize) + " , " + std::to_string(iFlags) + " )");

		return Font_t{ sPath, iSize, iFlags };
	}

	inline Texture_t SetupTexture(std::string sPath)
	{
		g_EmulatorEngine.WriteTrace("Render::SetupTexture ( " + sPath + " )");

		return Texture_t{ sPath };
	}
	
	inline void RenderText(std::string sText, Font_t Font, Vector2 vecPosition, int iSize, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderText ( " + sText + " , " + Font.m_sPath + " , " + std::to_string(Font.m_iSize) + " , " + std::to_string(Font.m_iFlags) + " , Vector2(" + std::to_string(vecPosition.m_flX) + " , " + std::to_string(vecPosition.m_flY) + "), " + std::to_string(iSize) + " , Color(" + std::to_string(Color.r) + " , " + std::to_string(Color.g) + " , " + std::to_string(Color.b) + " , " + std::to_string(Color.a) + ") )");
	}

	/* texture(tex, from, to, color)*/
	inline void RenderTexture(Texture_t Texture, Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderTexture ( " + Texture.m_sPath + " , Vector2(" + std::to_string(vecFrom.m_flX) + " , " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + " , " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + " , " + std::to_string(Color.g) + " , " + std::to_string(Color.b) + " , " + std::to_string(Color.a) + ") )");
	}
	
	inline Vector2 GetTextSize(Font_t Font, int iSize, std::string sText)
	{
		g_EmulatorEngine.WriteTrace("Render::GetTextSize ( " + Font.m_sPath + " , " + std::to_string(Font.m_iSize) + " , " + std::to_string(Font.m_iFlags) + " , " + std::to_string(iSize) + " , " + sText + " )");

		return Vector2(49, 50);
	}
	
	inline Vector2 GetCursorPos()
	{
		g_EmulatorEngine.WriteTrace("Render::GetCursorPos()");

		return Vector2(51, 52);
	}

	inline void RenderLine(Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderLine ( Vector2(" + std::to_string(vecFrom.m_flX) + " , " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + " , " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + " , " + std::to_string(Color.g) + " , " + std::to_string(Color.b) + " , " + std::to_string(Color.a) + ") )");
	}

	inline void RenderRect(Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderRect ( Vector2(" + std::to_string(vecFrom.m_flX) + " , " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + " , " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + " , " + std::to_string(Color.g) + " , " + std::to_string(Color.b) + " , " + std::to_string(Color.a) + ") )");
	}

	inline void RenderRectFilled(Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderRectFilled ( Vector2(" + std::to_string(vecFrom.m_flX) + " , " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + " , " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + " , " + std::to_string(Color.g) + " , " + std::to_string(Color.b) + " , " + std::to_string(Color.a) + ") )");
	}

	/* rect_filled_fade(from, to, col_upr_left, col_upr_right, col_bot_right, col_bot_left) */
	inline void RenderRectFilledFade(Vector2 vecFrom, Vector2 vecTo, Color_t ColorUpperLeft, Color_t ColorUpperRight, Color_t ColorBottomRight, Color_t ColorBottomLeft)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderRectFilledFade ( Vector2(" + std::to_string(vecFrom.m_flX) + " , " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + " , " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(ColorUpperLeft.r) + " , " + std::to_string(ColorUpperLeft.g) + " , " + std::to_string(ColorUpperLeft.b) + " , " + std::to_string(ColorUpperLeft.a) + "), Color(" + std::to_string(ColorUpperRight.r) + " , " + std::to_string(ColorUpperRight.g) + " , " + std::to_string(ColorUpperRight.b) + " , " + std::to_string(ColorUpperRight.a) + "), Color(" + std::to_string(ColorBottomRight.r) + " , " + std::to_string(ColorBottomRight.g) + " , " + std::to_string(ColorBottomRight.b) + " , " + std::to_string(ColorBottomRight.a) + "), Color(" + std::to_string(ColorBottomLeft.r) + " , " + std::to_string(ColorBottomLeft.g) + " , " + std::to_string(ColorBottomLeft.b) + " , " + std::to_string(ColorBottomLeft.a) + ") )");
	}
	/* circle_fade(pos, radius, color_in, color_out) */
	inline void RenderCircleFade(Vector2 vecPos, int iRadius, Color_t ColorIn, Color_t ColorOut)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderCircleFade ( Vector2(" + std::to_string(vecPos.m_flX) + " , " + std::to_string(vecPos.m_flY) + "), " + std::to_string(iRadius) + ", Color(" + std::to_string(ColorIn.r) + " , " + std::to_string(ColorIn.g) + " , " + std::to_string(ColorIn.b) + " , " + std::to_string(ColorIn.a) + "), Color(" + std::to_string(ColorOut.r) + " , " + std::to_string(ColorOut.g) + " , " + std::to_string(ColorOut.b) + " , " + std::to_string(ColorOut.a) + ") )");
	}

	/* circle(pos, radius, segments, filled, color) */
	inline void RenderCircle(Vector2 vecPos, int iRadius, int iSegments, bool bFilled, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderCircle ( Vector2(" + std::to_string(vecPos.m_flX) + " , " + std::to_string(vecPos.m_flY) + "), " + std::to_string(iRadius) + ", " + std::to_string(iSegments) + ", " + std::to_string(bFilled) + ", Color(" + std::to_string(Color.r) + " , " + std::to_string(Color.g) + " , " + std::to_string(Color.b) + " , " + std::to_string(Color.a) + ") )");
	}

	inline void FilledPolygon(std::vector < Vector2 > aPoints, Color_t Color)
	{
		std::string sPoints = "{ ";
		for (auto& Point : aPoints)
			sPoints += "Vector2(" + std::to_string(Point.m_flX) + " , " + std::to_string(Point.m_flY) + "), ";
		
		sPoints += "}";

		g_EmulatorEngine.WriteTrace("Render::FilledPolygon (" + sPoints + "Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + "))");
	}

}