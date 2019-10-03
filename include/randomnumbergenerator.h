#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H


class RandomNumberGenerator
{
	public:
		static int randomInt(int from, int tillIncl);
		static double randomDouble(double from, double tillIncl, int precision);

	private:
		RandomNumberGenerator(){};
		static bool initiated;
		static void checkIfInitiated();
};

#endif // RANDOMNUMBERGENERATOR_H
