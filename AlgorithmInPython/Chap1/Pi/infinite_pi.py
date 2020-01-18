def calculate_pi(n_terms: int) -> float:
    pi: float = 0.0
    denominator : float = 1.0
    operation: float = 1.0

    for i in range(n_terms):
        pi +=  operation * (4/denominator)
        denominator += 2.0
        operation *= -1.0

    return pi


print(calculate_pi(10000000))
