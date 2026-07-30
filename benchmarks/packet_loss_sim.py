import random

def simulate_burst_loss(packets, loss_rate=0.15):
    survived = [p for p in packets if random.random() > loss_rate]
    print(f"Packet loss test: {len(survived)} / {len(packets)} delivered ({loss_rate*100}% loss rate)")

if __name__ == '__main__':
    simulate_burst_loss(range(1000))
