#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

class Event {
public:
	long eventTime;
	
	Event();
	Event(long);
	std::vector<Event> processEvent();
};

Event::Event() : eventTime(0) {}

Event::Event(long t) : eventTime(t) {}

std::vector<Event> Event::processEvent() {
	int number;
	long aux;
	std::vector<Event> v;
	
	srand( time(0) );
	std::cout << "Processing event with time = " << eventTime << "\n";
	number = rand() % 3;
	std::cout << "Generating " << number << " events" << "\n";
	for (int i = 0; i < number; i++) {
		aux = (long) (rand() % 10 + 1);
		std::cout << "Creating an event with time " << (eventTime + aux) << "\n";
		v.push_back(Event(eventTime + aux));
	}
	return v;
}

int operator< (Event &left, Event &right) {
	return left.eventTime < right.eventTime;
}

void simulation() {
	std::priority_queue<Event> q;
	long currentTime = 0;
	
	q.push(Event());
	while (!q.empty() && currentTime < 100) {
		std::cout << "CURRENT TIME = " << currentTime;
		while (q.top().eventTime == currentTime) {
			Event e = q.top(); q.pop();
			std::vector<Event> v = e.processEvent();
			for (int i = 0; i < v.size(); i++) {
				q.push(v[i]);
			}
		}
		currentTime++;
	}
}

int main(int argc, char *argv[]) {
	simulation();
	return 0;
}
