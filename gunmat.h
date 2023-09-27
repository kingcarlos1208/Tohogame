# include <Siv3D.hpp>
# include <thread>

#ifndef EXAMPLE_A
#define EXAMPLE_A

class gunmat
{
private:
	
	Stopwatch stopwatch;
public:
	Vec2 position;
	std::string danganimage;
	Texture danganim;
	gunmat(Vec2 pos, std::string imagePath)
		:danganim(Texture(s3d::Unicode::FromUTF8(imagePath))),position(pos)
	{
		stopwatch.start();
		going(2,1);
	}
	void going(int speed,int omega)
	{
		const double elapsedSeconds = stopwatch.sF();
		position.x += (speed * elapsedSeconds) * cos(omega * elapsedSeconds);
		position.y += (speed * elapsedSeconds) * sin(omega*elapsedSeconds);
		danganim.draw(position);
	}
	void going1(int speed) {
		const double elapsedSeconds = stopwatch.sF();
		position.x += speed;
	}

};

#endif // EXAMPLE_H
