typedef struct result {
    bool is_error;
    int value;
}result;

result Result(bool is_error, int value) {
    result r;
    r.is_error = is_error;
    r.value = value;
    return r;
}