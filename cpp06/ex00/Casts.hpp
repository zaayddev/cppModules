#ifndef CASTS_HPP
# define CASTS_HPP

# include <string>

class Casts {
public:
  Casts(const std::string &input);
  ~Casts(void);

  const std::string &get_input(void) const;
  double get_value(void) const;
  void print(void) const;

private:
  Casts(void);
  Casts(const Casts &origin);
  Casts &operator=(const Casts &rhs);

  void print_to_char(void) const;
  void print_to_int(void) const;
  void print_to_float(void) const;
  void print_to_double(void) const;

  const std::string input_;
  const double value_;
};

#endif
