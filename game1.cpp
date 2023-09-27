# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include <vector>
#include <algorithm>  // std::remove_if のため
# include "steve.h"

void Main()
{
	//変数宣言
	int buffheigh = 600;
	int buffwidth = 800;
	Vec2 buff = { buffheigh,buffwidth };
	const VideoTexture haikei{U"img/game1/haikei.mp4",Loop::Yes };
	const Audio bgm(U"music/game1/bgm.mp3");
	const Image Image(U"music/game1/bgm.mp3");
	const Size frameSize = Image.size();
	const int haikeiwidth = frameSize.x;
	aoki* steve = new aoki("img/game1/aoki.png", buff);

	while (System::Update())
	{
		Window::Resize(600, 800);
		Scene::Resize(buffheigh, buffwidth); // ウィンドウの幅と高さを設定
		bgm.play();
		haikei.advance();
		haikei.resized(800, 800).drawAt(Scene::Center());
		steve->Draw();
		steve->Controll();
		steve->atack();
		FontAsset(U"Default")("Jesus").drawAt(buffheigh Palette::White);
	}
	delete steve;
}
