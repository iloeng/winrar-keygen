CC := g++
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	OPENSSL_INCLUDE_PATH := /usr/local/opt/openssl/include
	OPENSSL_LIB_PATH := /usr/local/opt/openssl/lib
else
	OPENSSL_INCLUDE_PATH :=	# use system default
	OPENSSL_LIB_PATH := # use system default
endif
MPIR_INCLUDE_PATH := # use system default
MPIR_LIB_PATH := # use system default

OUTPUT_DIR := ./bin/

KEYGEN_HEADER := \
	BigInteger.hpp \
	EllipticCurveGF2m.hpp \
	GaloisField.hpp \
	Hasher.hpp \
	HasherCrc32Traits.hpp \
	HasherSha1Traits.hpp \
	WinRarConfig.hpp \
	WinRarKeygen.hpp
KEYGEN_SOURCE := \
	_tmain.cpp

KEYGEN_BINARY = $(OUTPUT_DIR)winrar-keygen

keygen: $(KEYGEM_HEADER) $(KEYGEN_SOURCE)
	@if [ ! -d $(OUTPUT_DIR) ]; then mkdir -p $(OUTPUT_DIR); fi
	$(CC) -std=c++17 -O2 \
$(if $(OPENSSL_INCLUDE_PATH),-I$(OPENSSL_INCLUDE_PATH),) $(if $(OPENSSL_LIB_PATH),-L$(OPENSSL_LIB_PATH),) \
$(if $(MPIR_INCLUDE_PATH),-I$(MPIR_INCLUDE_PATH),) $(if $(MPIR_LIB_PATH),-L$(MPIR_LIB_PATH),) \
$(KEYGEN_SOURCE) \
-o $(KEYGEN_BINARY) \
-lcrypto -lmpir
	@echo 'Done.'

.PHONY: keygen

clean:
ifeq ($(wildcard $(KEYGEN_BINARY)), $(KEYGEN_BINARY))
	rm $(KEYGEN_BINARY)
endif
