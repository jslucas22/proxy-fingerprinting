# WebGL Vendor & Renderer Proxy

A simple HTTP proxy server designed to intercept and modify WebGL Vendor and Renderer from JavaScript responses.

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Security Considerations](#security-considerations)
- [Pros and Cons](#pros-and-cons)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project was developed to aid users in modifying the WebGL Vendor and Renderer from any web page through a proxy server. This can be particularly helpful in circumventing fingerprinting techniques based on WebGL properties, or simply to ensure a uniform identity across different browsing sessions.

## Installation

1. Clone the repository:
```bash
git clone https://github.com/jslucas22/proxy-fingerprinting.git
```
2. Navigate to the project directory:
```bash
cd src
```
3. Compile the project (make sure you have all the dependencies):
```bash
g++ main.cpp
```

## Usage

1. Start the proxy server: `./ProxyServer`

2. Configure your web browser to use `localhost:8080` as its proxy.
3. Browse the web as usual. JavaScript responses containing WebGL Vendor and Renderer will be modified.

## Security Considerations

When using this proxy, all your HTTP traffic will pass through it. Avoid using this proxy when accessing sensitive websites or transmitting personal data. Always make sure to disable the proxy after usage to prevent potential eavesdropping.

## Pros and Cons

### Pros:
- System-wide application: Affects all browsers on the system when properly configured.
- Difficult to detect: Unlike browser extensions, a network-level proxy is harder for websites to detect.
- Flexibility: Can be easily extended to modify other parts of HTTP traffic.

### Cons:
- Requires manual configuration of the browser or system settings.
- Slower browsing experience due to traffic redirection.
- Only affects HTTP traffic, not HTTPS, unless additional configuration and considerations are applied.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](LICENSE.md)
