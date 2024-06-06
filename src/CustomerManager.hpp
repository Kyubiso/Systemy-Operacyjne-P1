#include "src/Customer.h"
#include "src/Visualiser.h"
#include <unordered_set>
#include <memory>
class CustomerManager
{
private:
    /* data */
public:
    std::shared_ptr<std::unordered_set<std::shared_ptr<Customer>>> customers = std::make_shared<std::unordered_set<std::shared_ptr<Customer>>>();
    //auto customers = std::make_shared<std::unordered_set<std::shared_ptr<Customer>>>();
    CustomerManager(Visualiser window,  bool * stopFlag);
    ~CustomerManager() = default;
};
