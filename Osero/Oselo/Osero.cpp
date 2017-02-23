// Osero.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Osero.h"
#include<DXFunc.h>
#include"OseloObject.h"
#include<OseloClass.h>
#include<Coordinate.h>
#include"Test.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	Test();
	Init();

	unique_ptr<ObjectIF> obj(new OseloObject(CellNum(8,8),BoardClass::Cell_BLACK));
	Input input;

	obj->Init();
	
	while (MainLoop())
	{
		UpDate(obj,&input);
		Draw(obj);
		clsDx();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
