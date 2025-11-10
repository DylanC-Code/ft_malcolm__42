# 🧨 ft_malcolm

> A pedagogical ARP manipulation tool (spoofing / sniffing) built for the 42 curriculum — low-level networking, raw sockets and interface handling.

---

## 📁 Project Structure


```css
ft_malcolm/
├── srcs/
│   ├── core/
│   │   ├── arp_handler.c
│   │   ├── arp_receiver.c
│   │   ├── arp_sender.c
│   │   ├── arp_service.c
│   │   ├── arp_validator.c
│   │   ├── config_manager.c
│   │   └── config_validator.c
│   ├── domain/
│   │   ├── arp/
│   │   │   └── arp_parser.c
│   │   ├── ip_address.c
│   │   └── mac_address.c
│   ├── ft_malcolm.c
│   ├── infrastructure/
│   │   ├── cli/
│   │   │   ├── cli_config_parser.c
│   │   │   └── cli_usage.c
│   │   ├── iface/
│   │   │   ├── iface.c
│   │   │   └── iface_open.c
│   │   ├── log/
│   │   │   └── logger.c
│   │   ├── net/
│   │   │   ├── arp_printer.c
│   │   │   ├── arp_serializer.c
│   │   │   └── mac_parser.c
│   │   ├── permissions.c
│   │   └── signal/
│   │       └── signal_handler.c
│   └── shared/
│       └── hex_utils.c
├── includes/
│   └── *.h
├── Makefile
└── README.md
```

---

## 🧩 Overview

**ft_malcolm** is a learning project that exercises:
- Raw sockets (building and sending Ethernet/ARP frames)
- Packet capture and parsing
- Interface and MAC/IP manipulation
- Robustness: signal handling and ARP table restoration
- Usability: CLI parsing and hostname → IP resolution (bonus)

The pedagogical goal is to deeply understand how ARP works and how hosts on a LAN resolve MAC addresses from IP addresses.

---

## ⚠️ Warning & Ethics

This project constructs and sends network frames which **can disrupt a real network**.
**Never run ft_malcolm on a network you do not control** (production / corporate / public networks). Use a controlled lab (VMs, isolated network) only.

Always document in your defense that this tool is educational and state the legal and ethical implications.

---

## 🛠️ Prerequisites

- Linux (uses /proc/net/arp, ioctl SIOCGIFHWADDR, raw sockets)
- GCC
- Root privileges (required for raw sockets and sending Ethernet frames)
- make

---

## ⚙️ Build & Run

### Build

```bash
make
```

### Usage

```bash
sudo ./ft_malcolm <ip_source|hostname_source> <mac_source> <ip_target|hostname_target> <mac_target> [--verbose]
```

### Exit codes (examples)

- 0 : SUCCESS_EXIT_CODE
- 66 : NOT_ROOT_EXIT_CODE
- 67 : INVALID_ARGS_EXIT_CODE
- 68 : SPOOFING_EXIT_CODE

---

## 🔎 Hostname → IP (official bonus)

The official bonus in the subject refers only to hostname → IP resolution (DNS). Implement with `getaddrinfo()` + `inet_ntop()` to support IPv4/IPv6. This is a user-experience bonus — not the IP→MAC step (which is ARP and part of the core functionality).


---

## 🧑‍💻 Author

**Dylan C** — Student @ 42 Paris