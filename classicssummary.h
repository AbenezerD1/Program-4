#include <vector>
#include "classics.h"

class ClassicsSummary {
public:
    void add(Classics* classic) {
        if (summary.empty()) {
            summary.push_back(classic);
            return;
        }
        if (summary.at(0)->getMergeKey() != classic->getMergeKey()) {
            flush();
        }
        summary.push_back(classic);
    }
    void flush() {
        int total = 0;
        for (auto s : summary) {
            total += s->getStock();
        }
        std::cout << *summary.at(0) << std::setw(6) << total << std::endl;
        for (auto s : summary) {
            std::string name = s->getMajorActorFirstName() + " " + s->getMajorActorLastName();
            std::cout << std::string(51, ' ') << std::right << std::setw(21) << name
            << " --------------- "
            << s->getStock()
            << std::endl;
        }
        std::cout << std::endl;
        summary.clear();
    }
private:
    std::vector<Classics*> summary;
};