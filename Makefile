
python_test:
	$(MAKE) -C python test

cpp_test:
	$(MAKE) -C cpp test

test: python_test cpp_test

.PHONY: python_test cpp_test test


