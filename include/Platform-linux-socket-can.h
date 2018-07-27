#pragma once

namespace ctre {
namespace phoenix {
namespace platform {
namespace can {
    int SetCANInterface(const char * interface);
}
}
}
}

namespace ctre {
namespace phoenix {
namespace platform {
    void FeedWatchDog(int timeoutMs);
}
}
}
