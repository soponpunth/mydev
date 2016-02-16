#include "car_state.hpp"


std::map<float,Car> CarState::getCars(){
	return cars;
}


void CarState::updateCarState(float *data){
	float carId = *data++;
	Car car_structure = {
		carId, 
		*data++,  
		*data++,  
		*data++,
		*data++,
		*data++,
		*data++
	};
	cars[carId] = car_structure;

}

