# include <Siv3D.hpp>
# include <string>
# include <vector>
# include "gunmat.h"

#ifndef EXAMPLE_H
#define EXAMPLE_H

class aoki
{
public:
	Vec2 position;
	Vec2 thisbuff;
	std::string aokiface;
	Texture aokis;  // メンバ変数として Texture を宣言
	double velocity;
	double accelation;
	int hp;
	int maxhp;
	int power;
	int dansyu=0;
	Array<std::shared_ptr<gunmat>> dangan;

	aoki(std::string imagePath, Vec2 pos)
		: aokiface(imagePath), aokis(Texture(s3d::Unicode::FromUTF8(imagePath)))
	{
		position = { pos.x / 2,pos.y * 5 / 6 };
		thisbuff = pos;
		velocity = 0;
		accelation = 0;
	}

	void Draw()
	{
		aokis.draw(position);
	}
	void Controll()
	{
		// 左矢印キーが押された場合の処理
		if (KeyLeft.pressed()) {
			velocity -= 0.5;
		}

		// 右矢印キーが押された場合の処理
		if (KeyRight.pressed()) {
			velocity += 0.5;
		}
		if (KeyUp.pressed()) {
			position.y -= 5;
		}
		if (KeyDown.pressed()) {
			position.y += 5;
		}

		// 画面端でループする処理
		if (position.x>thisbuff.x) {
			position.x = 0.;

		}
		else if (position.x< 0) {
			position.x = thisbuff.x;
		}

		if (position.y >= thisbuff.y&&velocity>0) {

		}
		else if (position.y < 0) {
			position.y = 0;
		}
		if (velocity > 0) {
			velocity -= velocity / 25;
		}if (velocity < 0) {
			velocity -= velocity / 25;
		}

		velocity += accelation;
		position.x += velocity;
	}

	void Controll()
	{

	}

	void atack()
	{
		if (KeyK.pressed())
		{
			auto newDangan = std::make_shared<gunmat>(position, aokiface);
			dangan.push_back(newDangan);
		}

		// Update and draw bullets
		for (const auto& bullet : dangan)
		{
			if (dansyu = 0) {
				bullet->going(1, 5);
			}
			else if (dansyu = 1) {
				bullet->going1(10);
			}
			/*dangan.erase(std::remove_if(dangan.begin(), dangan.end(),
				[this](const auto& bullet) {  // [this] を追加して、ラムダ関数内でメンバ変数にアクセスできるようにします。
					return bullet->position.x < 0 || bullet->position.y < 0 || bullet->position.x > this->thisbuff.x;
				}), dangan.end());*/
		}
	}
};


#endif // EXAMPLE_H
