#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int              _value;
        static const int _nbBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &a);
		Fixed(const int v);
		Fixed(const float v);
        Fixed& operator=(const Fixed &a);
        ~Fixed();

		int		toInt(void) const;
		float	toFloat(void) const;
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
	};

std::ostream	&operator<<(std::ostream &str, const Fixed &a);