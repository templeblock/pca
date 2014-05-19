CFLAGS += -O3
CFLAGS += -std=c++0x 
CFLAGS += -pg -D_DEBUG -g -c -Wall 

COV_SRC = src/Cov
EIG_SRC = src/Eigen
DET_SRC = src/Determinant
PCA_SRC = src/PCA

LIB_TARGET = PCA
INC_TARGET = includes/ 	

INC_DIR= mkdir -p 

all: $(LIB_TARGET).so $(INC_TARGET)

$(LIB_TARGET).so:
	g++ -fPIC -std=c++0x -shared -o $(LIB_TARGET).so $(COV_SRC).cpp $(EIG_SRC).cpp $(DET_SRC).cpp $(PCA_SRC).cpp
 
$(INC_TARGET):
	$(INC_DIR) $(INC_TARGET) 

install:
	cp $(LIB_TARGET).so $(INC_TARGET)
	cp $(COV_SRC).h $(INC_TARGET)
	cp $(EIG_SRC).h $(INC_TARGET)
	cp $(PCA_SRC).h $(INC_TARGET)

uninstall:
	-rm $(LIB_TARGET).so 
	-rm -rf $(INC_TARGET)
	-rm -f $(INSTALL)
