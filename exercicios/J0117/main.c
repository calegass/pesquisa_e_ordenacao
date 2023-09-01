#include <stdio.h>
#include <math.h>

#define MAX_CITIES 10

typedef struct {
    int cityA;
    int cityB;
    int distance;
} Path;

int trueRoute(Path path, Path paths[], int numPaths) {
    if (path.cityB != 1) {
        for (int i = 0; i < numPaths; i++) {
            if ((paths[i].cityA == 1 || paths[i].cityB == 1) && (paths[i].cityA == path.cityA || paths[i].cityB == path.cityA)) {
                return 1; // Retorna 1 assim que encontrar uma rota válida
            }
        }
    }
    return 0; // Retorna 0 se não houver rota válida
}


int main() {
    Path paths[MAX_CITIES];
    int totalDistance = 0;
    int city, load;
    int taxation[MAX_CITIES];

    scanf("%d %d", &city, &load);

    for (int i = 0; i < city; i++) {
        scanf("%d", &taxation[i]);
    }

    for (int i = 0; i < city - 1; i++) {
        scanf("%d %d %d", &paths[i].cityA, &paths[i].cityB, &paths[i].distance);
    }

    for (int i = city - 2; i >= 0; i--) {
        int travel = 0;
        int routeLength = 0;

        if (trueRoute(paths[i], paths, city - 1)) {
            travel = ceil(taxation[paths[i].cityB - 1] / (float)load);
            taxation[paths[i].cityA - 1] += taxation[paths[i].cityB - 1];
            taxation[paths[i].cityB - 1] = 0;
        } else {
            travel = ceil(taxation[paths[i].cityA - 1] / (float)load);
            taxation[paths[i].cityB - 1] += taxation[paths[i].cityA - 1];
            taxation[paths[i].cityA - 1] = 0;
        }
        routeLength = 2 * paths[i].distance * travel;
        totalDistance += routeLength;
    }


    printf("%d\n", totalDistance);

    return 0;
}
