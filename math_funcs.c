// calculate mean, medium, mode, min, max, range of an array of integers
// gcc -o math_funcs math_funcs.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void print_array(char *txt, int *arry, int arry_size) {
    printf(txt);
    for (int i=0; i < arry_size; i++) {
        if (arry_size - 1 == i) {
            printf("%d", arry[i]);
        } else {
            printf("%d, ", arry[i]);
        }
    }
    printf("\n");
}

float mean(int *arry, int arry_size) {
    float sum = 0;
    for (int i=0; i < arry_size; i++) {
        sum += (float) arry[i];
    }
    return sum / arry_size;
}

float medium(int *arry, int arry_size) {
    int new_array[arry_size];
    memcpy(new_array, arry, arry_size * sizeof(int));
    qsort(new_array, arry_size, sizeof(int), compare);

    if (arry_size % 2 == 0) {
        return (new_array[arry_size / 2] + new_array[(arry_size / 2)+1]) / 2;
    } else {
        return new_array[arry_size / 2];
    }

}

int hashmap_index(int *hashmap, int hashmap_size, int key) {
    // finds the index of an integer within an array
    for (int i=0; i < hashmap_size; i += 2) {
        if (hashmap[i] == key) {
            return i;
        }
    }
    return -1;
}

void mode(int *arry, int arry_size) {
    int hashmap_size = arry_size * 2;
    int hashmap[hashmap_size];
    int index;
    int highest_count = 0;

    for (int i=0; i < hashmap_size; i++) {
        hashmap[i] = 0;
    }

    for (int i=0; i < arry_size; i++) {
        index = hashmap_index(hashmap, hashmap_size, arry[i]);
        if (index == -1) {
            hashmap[i * 2] = arry[i];
            hashmap[(i * 2)+1] = 1;
        } else {
            hashmap[index + 1]++;
            if (hashmap[index +1] > highest_count) {
                highest_count = hashmap[index + 1];
            }
        }
    }

    // output result
    int mode_arry[hashmap_size];
    int counter = 0;
    for (int i=0; i < hashmap_size; i += 2) {
        if (hashmap[i + 1] >= highest_count) {
            mode_arry[counter] = hashmap[i];
            counter++;
        }
    }
    print_array("Mode: ", mode_arry, counter);
}

float min(int *arry, int arry_size) {
    int smallest = arry[0];
    for (int i = 0; i < arry_size; i++) {
        if (arry[i] < smallest) {
            smallest = arry[i];
        }
    }
    return (float)smallest;
}

float max(int *arry, int arry_size) {
    int maximum = arry[0];
    for (int i = 0; i < arry_size; i++) {
        if (arry[i] > maximum) {
            maximum = arry[i];
        }
    }
    return (float)maximum;
}

float range(int *arry, int arry_size) {
    return max(arry, arry_size) - min(arry, arry_size);
}

float power(int n1, int n2) {
    int sum = 1;
    for (int i = 0;i < n2; i++) {
        sum *= n1;
    }
    return sum;
}

float variance(int *arry, int arry_size) {
    float u = mean(arry, arry_size);
    float sum = 0;

    for (int i = 0; i < arry_size; i++) {
        sum += power((arry[i] - u), 2);
    }
    return sum / arry_size;
}

float stddev(int *arry, int arry_size) {
    float v = variance(arry, arry_size);
    return sqrt(v);
}

int main() {
    int arry_size = 11;
    int arry[11] = {4,8,4,12,7,3,6,5,18,12,18};

    print_array("Array: ", arry, arry_size);
    printf("Mean: %f\n", mean(arry, arry_size));
    printf("Median: %f\n", medium(arry, arry_size));
    mode(arry, arry_size);
    printf("Min: %f\n", min(arry, arry_size));
    printf("Max: %f\n", max(arry, arry_size));
    printf("Range: %f\n", range(arry, arry_size));
    printf("Variance: %f\n", variance(arry, arry_size));
    printf("Standard Devitation: %f\n", stddev(arry, arry_size));
}
