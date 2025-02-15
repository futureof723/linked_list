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

void display_backwards(const Link* head) {
    if (head == nullptr) {
        return;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    while (head != nullptr) {
        std::cout << head->value << std::endl;
        head = head->prev;
    }
}
int main() {
    const auto thor = new Link("Thor");
    const auto odin = new Link("Odin", nullptr, nullptr);
    const auto freia = new Link("Freia", nullptr, nullptr);

    // Now linking the gods together: nullptr <-thor -> <- odin -> <-freia -> nullptr
    thor->next = odin;
    thor->prev = nullptr;
    odin->next = freia;
    odin->prev = thor;
    freia->next = nullptr;
    freia->prev = odin;

    std::cout << "==============================================" << std::endl;
    std::cout << "Traversing forwards:" << std::endl;
    // traversing the list forwards
    auto current = thor;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;
    }

    std::cout << "==============================================" << std::endl;
    std::cout << "Traversing backwards:" << std::endl;

    // traversing the list backwards
    auto backwards = freia;
    while (backwards != nullptr) {
        std::cout << backwards->value << std::endl;
        backwards = backwards->prev;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << "Using function to traverse forwards:" << std::endl;
    display_forwards(thor);

    std::cout << "==================================================" << std::endl;
    std::cout << "Using function to traverse backwards:" << std::endl;
    display_backwards(thor);



    // Delete all nodes to prevent memory leak
    delete freia;
    delete odin;
    delete thor;

}
