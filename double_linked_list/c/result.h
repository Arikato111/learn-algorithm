typedef struct result {
    // error if error is 1
    bool is_error;
    int value;
} result;

struct result Result(bool is_error, int value) {
    struct result r;
    r.is_error = is_error;
    r.value = value;
    return r;
}
