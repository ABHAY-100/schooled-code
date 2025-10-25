#include <stdio.h>

int main() {
    int in_packets, out_rate, num_arrivals, b_size, current_level = 0;

    printf("Enter the bucket size: ");
    scanf("%d", &b_size);

    printf("Enter the number of arrivals: ");
    scanf("%d", &num_arrivals);

    printf("Enter the outgoing rate: ");
    scanf("%d", &out_rate);

    while (num_arrivals > 0) {
        printf("\nEnter the number of packets arriving: ");
        scanf("%d", &in_packets);
        printf("Packets arrived: %d\n", in_packets);

        // leak packets
        current_level -= out_rate;

        if (current_level < 0) {
            current_level = 0;
        }

        if (in_packets <= (b_size - current_level)) {
            current_level += in_packets;
            printf("Bucket status: %d out of %d\n", current_level, b_size);
        } else {
            printf("Bucket overflow! Some packets dropped.\n");
            printf("Bucket status remains: %d out of %d\n", current_level, b_size);
        }

        num_arrivals--;
    }

    // continue leaking remaining packets
    while (current_level > 0) {
        current_level -= out_rate;

        if (current_level < 0) {
            current_level = 0;
        }
        
        printf("Leaking... bucket status: %d out of %d\n", current_level, b_size);
    }

    return 0;
}
