#ifndef myprint_h
#define myprint_h

class MyPrint {
public:
	template<typename T>
	void operator()(const T obj) {
		std::cout << obj << std::endl;
	}

	template<typename T>
	void operator()(T begin, const T end) {
		for (; begin != end; begin++) {
			std::cout << *begin << std::endl;
		}
	}
};

#endif
