#include <iostream>
#include <utility>

struct Link {
    std::string value;
    Link* prev;
    Link* next;

    explicit Link(std::string  value, Link* p = nullptr, Link* s = nullptr)
        : value(std::move(value)), prev(p), next(s) {}
};

void display_forwards(const Link* head) {
    if (head == nullptr) {
        return;
    }
    while (head != nullptr) {
        std::cout << head->value << std::endl;
        head = head->next;
    }
}

int main() {
    // Create the first node ("Thor")
    const auto thor = new Link("Thor");

    // Create the second node ("Odin"), linking it with "Thor"
    const auto odin = new Link("Odin", nullptr, thor);
    thor->prev = odin;

    // Create the third node ("Freia"), linking it with "Odin"
    const auto freia = new Link("Freia", nullptr, odin);
    odin->prev = freia;

    // Now the list is: "Thor" <-> "Odin" <-> "Freia"

    // traversing the list forwards
    auto current = freia;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;
    }

    std::cout << "==============================================" << std::endl;

    // traversing the list backwards
    auto backwards = thor;
    while (backwards != nullptr) {
        std::cout << backwards->value << std::endl;
        backwards = backwards->prev;
    }

    // Delete all nodes to prevent memory leak
    delete freia;
    delete odin;
    delete thor;

}
