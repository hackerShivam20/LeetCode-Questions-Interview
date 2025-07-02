class MedianFinder {
private:
    priority_queue<int> left; // max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> right; // min-heap for larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Push to max heap (left)
        left.push(num);

        // Step 2: Balance by pushing max from left to right
        right.push(left.top());
        left.pop();

        // Step 3: Maintain size invariant
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top(); // odd elements
        } else {
            return (left.top() + right.top()) / 2.0; // even elements
        }
    }
};