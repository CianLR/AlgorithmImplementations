
test: python_test cpp_test

python_test:
	$(MAKE) -C python test

cpp_test:
	$(MAKE) -C cpp test
	$(MAKE) -C cpp clean

.PHONY: python_test cpp_test test


