#include "pch.h"
#include "UITheme.h"
#include "UI.h"

void UITheme::DrawDyanmicBox(int x, int y, int w, int h, Texture2D* t, Texture2D* d, Texture2D* l, Texture2D* r, Texture2D* lt, Texture2D* ld, Texture2D* rt, Texture2D* rd, Texture2D* mid, float cr, float cg, float cb, float ca)
{

	UI::DrawTexture(lt, x, y, 16, 16, cr,cg,cb,ca);
	UI::DrawTexture(ld, x, y + h - 16, 16, 16, cr, cg, cb, ca);
	UI::DrawTexture(rt, x + w - 16, y, 16, 16, cr, cg, cb, ca);
	UI::DrawTexture(rd, x + w - 16, y + h - 16, 16, 16, cr, cg, cb, ca);
	UI::DrawTexture(l, x, y + 16, 16, h - 32, cr, cg, cb, ca);
	UI::DrawTexture(r, x + w - 16, y + 16, 16, h - 32, cr, cg, cb, ca);
	UI::DrawTexture(t, x + 16, y, w - 32, 16, cr, cg, cb, ca);
	UI::DrawTexture(d, x + 16, y + h - 16, w - 32, 16, cr, cg, cb, ca);
	UI::DrawTexture(mid, x + 16, y + 16, w - 32, h - 32,cr,cg,cb,ca);

}
