#pragma once

#include "Enigma/Core.h"

#include "Integer.h"

/*
	* Templated 1D Array 
*/
template <typename T, uint32 Nx>
class ENIGMA_API TArray
{
public:
	TArray() {}
	TArray(T Source)
	{
		uint32 Index = 0;
		while (Index < Nx)
		{
			Buffer[Index] = Source;
			++Index;
		}
	}

	uint32 GetSize() const { return Nx; }

	T operator[](uint32 Index)
	{
		ASSERT(Index < GetSize());
		return Buffer[Index];
	}

	T& operator[](uint32 Index)
	{
		ASSERT(Index < GetSize());
		return Buffer[Index];
	}

private:
	T Buffer[Nx];

};

/*
	* Templated 2D Array
*/
template <typename T, uint32 Nx, uint32 Ny>
class ENIGMA_API TArray2D
{
public:
	TArray2D() {}
	TArray2D(T Source)
	{
		uint32 Index = 0;
		uint32 Length = GetSize();
		while (Index < Length)
		{
			Buffer[Index] = Source;
		}
	}

	uint32 GetSize() const { return Nx * Ny; }

	T At(uint32 X, uint32 Y)
	{
		return Biffer[GetIndex(X, Y)];
	}

	T& At(uint32 X, uint32 Y)
	{
		return Biffer[GetIndex(X, Y)];
	}

	T operator[](uint32 Index)
	{
		ASSERT(Index < GetSize());
		return Buffer[Index];
	}

	T& operator[](uint32 Index)
	{
		ASSERT(Index < GetSize());
		return Buffer[Index];
	}


private:
	T Buffer[Nx * Ny];

	uint32 GetIndex(uint32 X, uint32 Y)
	{
		uint32 Index = X + Y * Nx;
		ASSERT(Index < GetSize());
		return Index;
	}

};

/*
	* Templated 3D Array
*/
template <typename T, uint32 Nx, uint32 Ny, uint32 Nz>
class ENIGMA_API TArray3D
{
public:
	TArray3D() {}
	TArray3D(T Source)
	{
		uint32 Index = 0;
		uint32 Length = GetSize();
		while (Index < Length)
		{
			Buffer[Index] = Source;
		}
	}

	uint32 GetSize() const { return Nx * Ny * Nz; }

	T At(uint32 X, uint32 Y, uint32 Z)
	{
		return Buffer[GetIndex(X, Y, Z)];
	}

	T& At(uint32 X, uint32 Y, uint32 Z)
	{
		return Buffer[GetIndex(X, Y, Z)];
	}

	T operator[](uint32 Index)
	{
		ASSERT(Index < GetSize());
		return Buffer[Index];
	}

	T& operator[](uint32 Index)
	{
		ASSERT(Index < GetSize());
		return Buffer[Index];
	}

private:
	T Buffer[Nx * Ny * Nz];

	uint32 GetIndex(uint32 X, uint32 Y, uint32 Z)
	{
		uint32 Index = 0;
		ASSERT(Index < GetSize());
		return Index;
	}

};