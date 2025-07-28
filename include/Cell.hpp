#ifndef __CELL__
	#define __CELL__

	class Cell
	{
	public:
		Cell(int age);
		Cell();
		~Cell();
		void grow();
		int getAge();

	private:
		int age;
	};

#endif

