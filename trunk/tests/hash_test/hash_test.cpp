#include <string>
#include "persistent_hash.hpp"
#include "persistent_string.hpp"
#include "persistent_int.hpp"
#include "persistent_shortcuts.hpp"
#include "dprintf.hpp"
#include "file_system.hpp"

////////////////////////////////////////////////////////////////////////////////

#define NUMBER 1000
#define DATA "hash_test.tmp"
#define MASTER "hash_test.dump"

////////////////////////////////////////////////////////////////////////////////

class hash_int
{
public:
  unsigned operator () (int value)
    {return (unsigned)value;}
};

////////////////////////////////////////////////////////////////////////////////

typedef stlplus::hash<int,std::string,hash_int> int_string_hash;

void dump_int_string_hash(stlplus::dump_context& context, const int_string_hash& data)
{
  stlplus::dump_hash(context, data, stlplus::dump_int, stlplus::dump_string);
}

void restore_int_string_hash(stlplus::restore_context& context, int_string_hash& data)
{
  stlplus::restore_hash(context, data, stlplus::restore_int, stlplus::restore_string);
}

bool compare(const int_string_hash& left, const int_string_hash& right)
{
  bool result = true;
  if (left.size() != right.size())
  {
    std::cerr << "different size - left = " << left.size() << " right = " << right.size() << std::endl;
    result = false;
  }
  for (int_string_hash::const_iterator j  = left.begin(); j != left.end(); j++)
  {
    if (!right.present(j->first))
    {
      std::cerr << "left = " << j->first << " right is missing" << std::endl;
      result = false;
    }
    else if (j->second != right[j->first])
    {
      std::cerr << "left = \"" << j->second << "\" is different from right = \"" << right[j->first] << "\"" << std::endl;
      result = false;
    }
  }
  return result;
}

////////////////////////////////////////////////////////////////////////////////

int main(unsigned argc, char* argv[])
{
  bool result = true;
  std::cerr << "testing " << NUMBER << " mappings" << std::endl;

  try
  {
    // build the sample data structure
    int_string_hash data;
    for (unsigned i = 0; i < NUMBER; i++)
      data[i] = stlplus::dformat("%d",i);
    // now dump to the file
    std::cerr << "dumping" << std::endl;
    stlplus::dump_to_file(data,DATA,dump_int_string_hash,0);

    // now restore the same file and compare
    std::cerr << "restoring" << std::endl;
    int_string_hash restored;
    stlplus::restore_from_file(DATA,restored,restore_int_string_hash,0);
    result &= compare(data,restored);

    // compare with the master dump if present
    if (!stlplus::file_exists(MASTER))
      stlplus::file_copy(DATA,MASTER);
    else
    {
      std::cerr << "restoring master" << std::endl;
      int_string_hash master;
      stlplus::restore_from_file(MASTER,master,restore_int_string_hash,0);
      result &= compare(data,master);
    }
  }
  catch(std::exception& except)
  {
    std::cerr << "caught standard exception " << except.what() << std::endl;
    result = false;
  }
  catch(...)
  {
    std::cerr << "caught unknown exception" << std::endl;
    result = false;
  }

  if (!result)
    std::cerr << "test failed" << std::endl;
  else
    std::cerr << "test passed" << std::endl;
  return result ? 0 : 1;
}
