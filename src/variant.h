#pragma once

#include "types.h"

struct fuck;
class variant 
{
public:

	enum Type 
	{
		NIL,		
		
		// atomic types 		
		BOOL,
		INT,
		REAL,
		STRING,

		// pointer
		POINTER,
		
		VARIANT_MAX
	};	
    
    
	variant(const variant& p_variant);
	variant() { m_type = NIL; m_fk = 0; }
	variant(fuck * fk) { m_type = NIL; m_fk = fk; }
	~variant() { if (m_type != variant::NIL) clear(); }

	variant(bool p_bool, fuck * fk);
	variant(signed int p_int, fuck * fk); // real one
	variant(unsigned int p_int, fuck * fk);
	variant(signed short p_short, fuck * fk); // real one
	variant(unsigned short p_short, fuck * fk);
	variant(signed char p_char, fuck * fk); // real one
	variant(unsigned char p_char, fuck * fk);
	variant(int64_t p_char, fuck * fk); // real one
	variant(uint64_t p_char, fuck * fk);
	variant(float p_float, fuck * fk);
	variant(double p_double, fuck * fk);
	variant(const String& p_string, fuck * fk);
	variant(const char * const p_cstring, fuck * fk);
	variant(void * p_ptr, fuck * fk);
	
	bool operator==(const variant& p_variant) const;	
	void operator=(const variant& p_variant); // only this is enough for all the other types

    void operator +=(const variant& p_variant);
	void operator -=(const variant& p_variant);
	void operator *=(const variant& p_variant);
	void operator /=(const variant& p_variant);
	void operator %=(const variant& p_variant);
	
	operator bool() const;
	operator int() const;
	operator unsigned int() const; // this is the real one
	operator short() const;
	operator unsigned short() const;
	operator char() const;
	operator unsigned char() const;
	operator int64_t() const;
	operator uint64_t() const;
	operator float() const;
	operator double() const;
	operator String() const;
	operator void*() const;

	Type get_type() const { return m_type; }
	static String get_type_name(variant::Type p_type);

	uint32_t hash() const;

	bool booleanize() const;

private:

	union MemData
	{
		bool m_bool;
		int64_t m_int;
		double m_real;
		String * m_str;
		void * m_ptr; //generic pointer
	};

	void clear();
	void reference(const variant& p_variant);
	
private:

	Type m_type;

	MemData m_data;

	fuck * m_fk;
};

typedef std::vector<variant> const_list;
typedef std::vector<variant> variant_list;

