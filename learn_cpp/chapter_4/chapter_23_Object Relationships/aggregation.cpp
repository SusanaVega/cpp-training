#include <iostream>
#include <string>
#include <functional> // std::reference_wrapper



class Teacher
{
  private:
    std::string_view m_name;
  public:
    Teacher(std::string_view name) : m_name {name}
	{

	}
    const std::string_view& getName() const {return m_name;}
};

class Department
{
	private:
    std::vector<std::reference_wrapper<const Teacher>> m_department;
	public:
    Department() = default;
	friend std::ostream& operator<<(std::ostream& out, const Department& d)
	{
		out << "Deparment: ";
		for(auto name :d.m_department)
		{
			out << name.get().getName() << " ";
		}
		out << std::endl;
		return out;
	}

	void add(const Teacher& teacher)
	{
		m_department.push_back(teacher);
	}


};


int main()
{
  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}