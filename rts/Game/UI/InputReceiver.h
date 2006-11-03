#ifndef INPUTRECEIVER_H
#define INPUTRECEIVER_H

#include "Object.h"
#include <deque>
#include <string>

class CInputReceiver :
	public CObject
{
public:
	CInputReceiver(void);
	virtual ~CInputReceiver(void);

	virtual bool KeyPressed(unsigned short key){return false;};
	virtual bool KeyReleased(unsigned short key){return false;};

	virtual bool MousePress(int x, int y, int button){return false;};
	virtual void MouseMove(int x, int y, int dx,int dy, int button){};
	virtual void MouseRelease(int x, int y, int button){};
	virtual bool IsAbove(int x, int y){return false;};
	virtual void Draw(){};
	virtual std::string GetTooltip(int x,int y){return "No tooltip defined";};

	static void CollectGarbage();
	static CInputReceiver* GetReceiverAt(int x,int y);

	struct ContainerBox {
		ContainerBox();
		ContainerBox operator+(ContainerBox other);

		float x1;
		float y1;
		float x2;
		float y2;
	};
	bool InBox(float x, float y, const ContainerBox& box);
	void DrawBox(const ContainerBox& b, int how = -1);

	// transform from mouse (x,y) to opengl (x,y) (first in screen pixels,
	// second in orthogonal projection 0-1 left-right, bottom-top)
	static float MouseX(int x) { return float(x-gu->screenxPos)/gu->screenx; }
	static float MouseY(int y) { return float(gu->screeny-y)/gu->screeny; }
	static float MouseMoveX(int x) { return float(x)/gu->screenx; }
	static float MouseMoveY(int y) { return -float(y)/gu->screeny; }

	static float guiAlpha;
};

std::deque<CInputReceiver*>& GetInputReceivers();

#endif /* INPUTRECEIVER_H */

