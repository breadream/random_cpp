template <class T, class Container = std::vector<T>,
          class Compare = std::less<T> >
class priority_queue {
protected:
    Container c;
    Compare comp;
 
public:
    explicit priority_queue(const Container& c_  = Container(),
                            const Compare& comp_ = Compare())
        : c(c_), comp(comp_)
    {
        std::make_heap(c.begin(), c.end(), comp);
    }
 
    bool empty()       const { return c.empty(); }
    std::size_t size() const { return c.size(); }
 
    const T& top()     const { return c.front(); }
 
    void push(const T& x)
    {
        c.push_back(x);
        std::push_heap(c.begin(), c.end(), comp);
    }
    
    void pop()
    {
        std::pop_heap(c.begin(), c.end(), comp);
        c.pop_back();
    }
};
