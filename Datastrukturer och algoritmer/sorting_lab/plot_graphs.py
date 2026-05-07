import os
import math
import pandas as pd
import matplotlib.pyplot as plt


RESULTS_DIR = "results"
OUTPUT_DIR = "plots"

os.makedirs(OUTPUT_DIR, exist_ok=True)


def read_dat_file(filename):
    path = os.path.join(RESULTS_DIR, filename)
    return pd.read_csv(path, sep=r"\s+", engine="python")


def plot_algorithm_family(prefix, title, theoretical=None):
    """
    prefix ex:
    'insertion'
    'selection'
    'quicksort_right'
    'quicksort_median3'
    'stdsort'
    """

    patterns = ["random", "rising", "falling", "constant"]

    plt.figure(figsize=(10, 6))

    for pattern in patterns:
        filename = f"{prefix}.{pattern}.dat"
        df = read_dat_file(filename)

        plt.plot(
            df["N"],
            df["mean_ms"],
            marker="o",
            label=pattern
        )

    # enkel teoretisk passning
    if theoretical is not None:
        df_ref = read_dat_file(f"{prefix}.random.dat")
        x = df_ref["N"]

        if theoretical == "n2":
            k = df_ref["mean_ms"].iloc[-1] / (x.iloc[-1] ** 2)
            y_fit = k * (x ** 2)
            ##plt.plot(x, y_fit, linestyle="--", label="Fit k·N²")

        elif theoretical == "nlogn":
            k = df_ref["mean_ms"].iloc[-1] / (x.iloc[-1] * math.log2(x.iloc[-1]))
            y_fit = [k * n * math.log2(n) for n in x]
            ##plt.plot(x, y_fit, linestyle="--", label="Fit k·N log₂N")

    #plt.title(title)
    #plt.xlabel("N")
    #plt.ylabel("Tid (ms)")
    #plt.xticks([])  #
    #plt.yticks([])  #
    #plt.tick_params(bottom=False, left=False)  #
    #plt.legend()
    #plt.grid(True)
    #plt.tight_layout()
    #plt.show();
    #outpath = os.path.join(OUTPUT_DIR, f"{prefix}.png")
    #plt.savefig(outpath, dpi=200)
    #plt.close()
    plt.title(title)
    plt.xlabel("N")
    plt.ylabel("Tid (ms)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

def main():
    plot_algorithm_family("insertion", "Insertion sort", theoretical="n2")
    plot_algorithm_family("selection", "Selection sort", theoretical="n2")
    plot_algorithm_family("quicksort_right", "Quicksort (right pivot)", theoretical="nlogn")
    plot_algorithm_family("quicksort_median3", "Quicksort (median-of-three)", theoretical="nlogn")
    plot_algorithm_family("stdsort", "std::sort", theoretical="nlogn")

    print("Klart! Grafer sparade i mappen plots/.")


if __name__ == "__main__":
    main()