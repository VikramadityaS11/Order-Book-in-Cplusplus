// Order info

enum class Side {
    BUY,
    SELL
};

enum class OrderType {
    MARKET,
    LIMIT
};

struct Order {
    OrderType orderType;
    Side side;
    double price;
    int quantity;
};