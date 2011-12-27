#include <QDebug>
#include <QThread>

#include "ortp/ortp.h"

#define RTP_PORT 10010
#define RTP_BUFFER_LENGTH 1024

class RTP : public QThread {
    Q_OBJECT

    public:
        RTP();
        virtual ~RTP();
        int init(char* host,int port);
        void run();
        void shutdown();
        void send(unsigned char *buffer, int length);
        void dump_buffer(unsigned char* buffer,int length);

    signals:
        void rtp_packet_received(char* buffer,int length);

    public slots:
        void setRemote(char* host,int port);

    private:
        int initialized;
        int remote_set;
        RtpSession* rtpSession;
        int jittcomp;
        bool_t adapt;
        int cont;
        uint32_t recv_ts;
        uint32_t send_ts;

 };
