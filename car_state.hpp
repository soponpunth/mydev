#include <map>

#define MAX_CARS 8


struct Car {
	float car_id, x, y, vx, vy, ax, ay;
};

class CarState {
	std::map<float, Car> cars;

	public:
		void updateCarState(float *);
		std::map<float,Car> getCars();

};
