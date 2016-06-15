#include "oscListener.hpp"


void raspiTest::dioStart() {

    // init dio
    for(int i=0; i<1; i++){
        Dacs1500rcp24 dio(i);
        dioList.push_back(dio);
    }

    // device open
    for(int i=0; i<1; i++) dioList[i].open();

    // lamp on -> off
    for(int i=0; i<1; i++) {
        command = dioList[i].getDigitalOutPutCommand("800000");
      dioList[i].sendCommand(command);
    }
    sleep(2);
    for(int i=0; i<1; i++) {
        command = dioList[i].getDigitalOutPutCommand("000000");
        dioList[i].sendCommand(command);
    }
    sleep(2);

    // pwm init
    for(int i=0; i<1; i++) {
        command = dioList[i].getPWMInitializeCommand(3,20000);
        dioList[i].sendCommand(command);
    }

    // pwm init pos
    for(int i=0; i<1; i++) {
        for(int j=0; j<PWM_CHANNEL_NUM; j++) values.push_back(1450);
        command = dioList[i].getPWMPalseChangeCommand(values);
        dioList[i].sendCommand(command);
    }

    // start
    for(int i=0; i<1; i++) {
        command = dioList[i].getPWMStartCommand();
        dioList[i].sendCommand(command);
    }
}


void raspiTest::dioStop() {
    // device pwm stop
    for(int i=0; i<1; i++) {
        command = dioList[i].getPWMStopCommand();
        dioList[i].sendCommand(command);
    }

    // device close
    for(int i=0; i<1; i++) dioList[i].close();
}


void raspiTest::ProcessMessage( const osc::ReceivedMessage& m,
                                const IpEndpointName& remoteEndpoint )
{
    try{
        if( strcmp( m.AddressPattern(), "/deviceA" ) == 0 ){
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            osc::int32 val0, val1, val2, val3, val4, val5,
                    val6, val7, val8, val9, val10, val11,
                    val12, val13, val14, val15, val16, val17,
                    val18, val19, val20, val21, val22, val23;

            args >> val0 >> val1 >> val2 >> val3 >> val4 >> val5
                    >> val6 >> val7 >> val8 >> val9 >> val10 >> val11
                    >> val12 >> val13 >> val14 >> val15 >> val16 >> val17
                    >> val18 >> val19 >> val20 >> val21 >> val22 >> val23
                    >> osc::EndMessage;
            std::cout << "received '/deviceA' message with arguments: "
                      << val0 << " " << val1 << " " << val2 << " " << val3 << " "
                      << val4 << " " << val5 << " " << val6 << " " << val7 << " "
                      << val8 << " " << val9 << " " << val10 << " " << val11 << " "
                      << val12 << " " << val13 << " " << val14 << " " << val15 << " "
                      << val16 << " " << val17 << " " << val18 << " " << val19 << " "
                      << val20 << " " << val21 << " " << val22 << " " << val23 << " "
                      << "\n";

        } else if( strcmp( m.AddressPattern(), "/deviceB" ) == 0 ){
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            osc::int32 val0, val1, val2, val3, val4, val5,
                    val6, val7, val8, val9, val10, val11,
                    val12, val13, val14, val15, val16, val17,
                    val18, val19, val20, val21, val22, val23;

            args >> val0 >> val1 >> val2 >> val3 >> val4 >> val5
                    >> val6 >> val7 >> val8 >> val9 >> val10 >> val11
                    >> val12 >> val13 >> val14 >> val15 >> val16 >> val17
                    >> val18 >> val19 >> val20 >> val21 >> val22 >> val23
                    >> osc::EndMessage;
            std::cout << "received '/deviceB' message with arguments: "
                      << val0 << " " << val1 << " " << val2 << " " << val3 << " "
                      << val4 << " " << val5 << " " << val6 << " " << val7 << " "
                      << val8 << " " << val9 << " " << val10 << " " << val11 << " "
                      << val12 << " " << val13 << " " << val14 << " " << val15 << " "
                      << val16 << " " << val17 << " " << val18 << " " << val19 << " "
                      << val20 << " " << val21 << " " << val22 << " " << val23 << " "
                      << "\n";

        } else if( strcmp( m.AddressPattern(), "/deviceC" ) == 0 ){
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            osc::int32 val0, val1, val2, val3, val4, val5,
                    val6, val7, val8, val9, val10, val11,
                    val12, val13, val14, val15, val16, val17,
                    val18, val19, val20, val21, val22, val23;

            args >> val0 >> val1 >> val2 >> val3 >> val4 >> val5
                    >> val6 >> val7 >> val8 >> val9 >> val10 >> val11
                    >> val12 >> val13 >> val14 >> val15 >> val16 >> val17
                    >> val18 >> val19 >> val20 >> val21 >> val22 >> val23
                    >> osc::EndMessage;
            std::cout << "received '/deviceC' message with arguments: "
                      << val0 << " " << val1 << " " << val2 << " " << val3 << " "
                      << val4 << " " << val5 << " " << val6 << " " << val7 << " "
                      << val8 << " " << val9 << " " << val10 << " " << val11 << " "
                      << val12 << " " << val13 << " " << val14 << " " << val15 << " "
                      << val16 << " " << val17 << " " << val18 << " " << val19 << " "
                      << val20 << " " << val21 << " " << val22 << " " << val23 << " "
                      << "\n";

        }  else if( strcmp( m.AddressPattern(), "/deviceD" ) == 0 ){
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            osc::int32 val0, val1, val2, val3, val4, val5,
                    val6, val7, val8, val9, val10, val11,
                    val12, val13, val14, val15, val16, val17,
                    val18, val19, val20, val21, val22, val23;

            args >> val0 >> val1 >> val2 >> val3 >> val4 >> val5
                    >> val6 >> val7 >> val8 >> val9 >> val10 >> val11
                    >> val12 >> val13 >> val14 >> val15 >> val16 >> val17
                    >> val18 >> val19 >> val20 >> val21 >> val22 >> val23
                    >> osc::EndMessage;
            std::cout << "received '/deviceD' message with arguments: "
                      << val0 << " " << val1 << " " << val2 << " " << val3 << " "
                      << val4 << " " << val5 << " " << val6 << " " << val7 << " "
                      << val8 << " " << val9 << " " << val10 << " " << val11 << " "
                      << val12 << " " << val13 << " " << val14 << " " << val15 << " "
                      << val16 << " " << val17 << " " << val18 << " " << val19 << " "
                      << val20 << " " << val21 << " " << val22 << " " << val23 << " "
                      << "\n";
        }
    } catch( osc::Exception& e ) {
        std::cout << "error while parsing message: "
                  << m.AddressPattern() << ": " << e.what() << "\n";
    }
}
